#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <stdint.h>
#include <algorithm>
#include "file_reader.h"

using namespace std;

string file_path = "./02_sample_data/10Neighbours_30PercentRed/tree_10neigh_v0.txt";

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool does_file_exist(string &user_file_path)
{
	string line;

	/* User used default */

	if (user_file_path == "default")
	{
		cout << "User didn't provide any path.\n";
		cout << "Using default path: " << file_path << '\n';
	}
	else
	{
		file_path = user_file_path;
	}

	ifstream input_file (file_path);

	/* Try to open a file */
	if (!input_file.is_open())
	{
		cout << "Unable to find desired file. Please check corectness of provided filename.\n";
		return false;
	}

	/* Try to read a line from file */
	if (!getline(input_file, line))
	{
		cout << "Failed while trying to open a file.\n";
		return false;
	}

	cout << "File opened successfully.\n";

	input_file.close();

	return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool get_graph_from_file(struct square_graph *graph)
{
	string tmp;
	string number = "";
	uint16_t index = 0;
	
	ifstream file_stream;
	file_stream.open(file_path);

	/* Skip two lines */
	getline(file_stream, tmp);
	getline(file_stream, tmp);

	/* Fill up matix array */
	for (int i = 0; i < graph->size; ++i)
	{
		/* Set '1' to the right fields of matrix */
		tmp.erase(remove(tmp.begin(), tmp.end(), ' '), tmp.end());
		tmp.erase(remove(tmp.begin(), tmp.end(), ','), tmp.end());

		size_t one_index = tmp.find_first_of('1');

		while (one_index != std::string::npos)
		{
			graph->nodes_matrix[graph->size * i + one_index] = 0x01;
			one_index = tmp.find_first_of('1', one_index + 1);
		}

		getline(file_stream, tmp);	
	}

	/* Read and set neighbours nodes */
	getline(file_stream, tmp);

	tmp.erase(remove(tmp.begin(), tmp.end(), ' '), tmp.end());
	cout << tmp << endl;

	for(int k = 0; k < tmp.length() - 1; ++k)
	{
		number += tmp[k];

		if(tmp[k] == ',')
		{
			int neighbour_index = stoi(number);
			graph->nodes_matrix[neighbour_index] = 0x81;
			number = "";
		} 
	}

	return true;
} 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool allocate_space_for_graph(struct square_graph *graph)
{
	graph->nodes_matrix = new (nothrow) uint8_t [graph->size * graph ->size];

	memset(graph->nodes_matrix, 0, graph->size * graph->size * sizeof(uint8_t));

	if(graph->nodes_matrix == NULL) 
		return false;

	return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void print_graph(struct square_graph *graph)
{
	/* Printing graph matrix */
	cout << graph->size << endl;
	cout << "Graph matrix:" << endl;

	for (int i = 0; i < graph->size; ++i)
	{
		for (int j = 0; j < graph->size; ++j)
			cout << (int)graph->nodes_matrix[graph->size * i + j] << " ";

		cout << endl;
	}

	cout << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool get_size_of_matrix(struct square_graph *graph)
{
	string tmp;

	/* Opening file */
	ifstream file_stream;
	
	file_stream.open(file_path);

	/* Skip first line */
	getline(file_stream, tmp);

	/* Get first line, and check matrix size*/
	getline(file_stream, tmp);

	/* Set right size of matrix */
	if (tmp.find_last_of('0') == std::string::npos)
		return false;

	graph->size = tmp.find_last_of('0')/3 + 1;

	return true;
}