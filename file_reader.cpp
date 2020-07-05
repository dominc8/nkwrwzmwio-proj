#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

string file_path = ".\\02_sample_data\\10Neighbours_30PercentRed\\tree_10neigh_v0.txt";

bool does_file_exist(string user_file_path)
{
	string line;

	/* User didn't specified new path */
	if (user_file_path.length() != 0)
	{
		file_path = user_file_path;
	}
	else
	{
		cout << "User didn't provide any path.\n";
		cout << "Using default path: " << user_file_path << '\n';
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

int ** extract_graph_from_file(string file_path)
{
	string tmp;
	string number;
	int size_of_graph;
	int ** p_graph;
	int matrix_size;
	size_t one_index;
	int neighbour_index;

	/* Opening file */
	ifstream file_stream;
	file_stream.open(file_path);

	/* Skip first line */
	getline(file_stream, tmp);

	/* Get first line, and check matrix size*/
	getline(file_stream, tmp);
	size_of_graph = tmp.length();

	/* Set right size of matrix */
	matrix_size = (size_of_graph - 1)/3;

	/* Allocate adequete memory block for matrix and extract data*/
	p_graph = new (nothrow) int * [matrix_size];
	for (int i = 0; i < matrix_size; ++i)
	{
		p_graph[i] = new (nothrow) int[matrix_size];
		memset(p_graph[i], 0, matrix_size*sizeof(int));

		/* Set '1' to the right fields of matrix */
		one_index = tmp.find_first_of('1');
		while (one_index != std::string::npos)
		{
			p_graph[i][one_index/3] = 1;
			one_index = tmp.find_first_of('1', one_index+1);
		}
		getline(file_stream, tmp);	
	} 

	// Check if p_graph pointer is not NULL
	if(p_graph == NULL) 
	{
		cout << "Memory allocation failed." << endl;
		return p_graph;
	}
	cout << "Memory allocated correctlly." << endl;

	/* Set "neighbours" on the diagonal of the matrix */
	getline(file_stream, tmp);
	cout << tmp;

	for(int k = 0; k < tmp.length() - 1; ++k)
	{
		number += tmp[k];

		if(tmp[k + 1] == ',')
		{
			neighbour_index = stoi(number);
			cout << neighbour_index << endl;
			p_graph[neighbour_index][neighbour_index] = -2;
			number = "";
		} 
		else if ((k + 1) == " ")
		{
			/* code */
		}

	}

	cout << "Data extracted correctlly" << endl;
	file_stream.close();
	return p_graph;
} 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////