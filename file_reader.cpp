#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string file_path = "./02_sample_data/10Neighbours_30PercentRed/tree_10neigh_v0.txt";


//////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool does_file_exist(const string &user_file_path)
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

bool extract_graph_from_file(int ** graph_matrix, int matrix_size, vector<int> &neighbours_v)
{
	string tmp;
	string number;
	size_t one_index;
	int neighbour_index;

	/* Opening file */
	ifstream file_stream;
	file_stream.open(file_path);

	/* Skip two lines */
	getline(file_stream, tmp);
	getline(file_stream, tmp);

	/* fill up matix array */
	for (int i = 0; i < matrix_size; ++i)
	{
		memset(graph_matrix[i], 0, matrix_size*sizeof(int));

		/* Set '1' to the right fields of matrix */
		one_index = tmp.find_first_of('1');
		while (one_index != std::string::npos)
		{
			graph_matrix[i][one_index/3] = 1;
			one_index = tmp.find_first_of('1', one_index+1);
		}
		getline(file_stream, tmp);	
	} 

	/* Set "neighbours" of the matrix */
	getline(file_stream, tmp);
	for(int k = 0; k < tmp.length() - 1; ++k)
	{
		number += tmp[k];

		if(tmp[k] == ',')
		{
			neighbour_index = stoi(number);
			neighbours_v.push_back(neighbour_index);
			number = "";
		} 
	}

	cout << "Data extracted correctlly" << endl;
	file_stream.close();

	/* Assaing arrays to input arrays */
	return true;
} 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ** allocate_space_for_graph_matrix(int matrix_size)
{
	string tmp;
	int ** p_graph;

	/* Opening file */
	ifstream file_stream;
	file_stream.open(file_path);

	/* Skip two lines */
	getline(file_stream, tmp);
	getline(file_stream, tmp);

	/* Allocate adequete memory block for matrix and extract data*/
	p_graph = new (nothrow) int * [matrix_size];
	for (int i = 0; i < matrix_size; ++i)
	{
		p_graph[i] = new (nothrow) int[matrix_size];
		getline(file_stream, tmp);	
	} 

	// Check if p_graph pointer is not NULL
	if(p_graph == NULL) 
	{
		cout << "Memory allocation failed." << endl;
		return p_graph;
	}
	cout << "Memory allocated correctlly." << endl;	

	return p_graph;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void print_graph_matrix_and_neighbours(int ** in_graph, int rows, int columns, vector<int> &in_neighbours)
{

	/* Printing graph matrix */
	cout << "Graph matrix:" << endl;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			cout << in_graph[i][j] << " ";
		}
		cout << endl;
	}


	/* Printing neighbours vector */
	cout << "Neighbours:" << endl;
	for (int k = 0; k < in_neighbours.size(); ++k)
	{
		cout << in_neighbours[k] << " ";
	}

	cout << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int get_size_of_matrix()
{
	string tmp;
	int matrix_size;
	int size_of_graph;

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

	return matrix_size;
}
