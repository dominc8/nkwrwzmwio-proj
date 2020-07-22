#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include "file_reader.h"

using namespace std;

bool read_data_from_file(struct square_graph *main_graph)
{
	string user_file_path;

	/* Get filepath from user and check if it exists */
	while(1)
	{
		std::cout << "Please provide path to your input file:" << endl;
		std::cout << "(To provide default file path please type 'default')" << endl;

		std::cin >> user_file_path;

		if (does_file_exist(user_file_path)) 
			break;
	}

	if (!get_size_of_matrix(main_graph))
	{
		cout << "Getting graph size failed!" << endl;
		return false;
	}

	if (!allocate_space_for_graph(main_graph))
	{
		cout << "Failed to allocate memory for graph!" << endl;
		return false;
	}

	if (!get_graph_from_file(main_graph))
	{
		cout << "Getting data form file failed!" << endl;
		return false;
	}

	cout << "Graph read succesfully!" <<endl;

	return true;
}


int main(int argc, char const *argv[])
{
	struct square_graph main_graph;

	if (!read_data_from_file(&main_graph))
		return 0;

	print_graph( &main_graph);

	delete[] main_graph.nodes_matrix;

	return 0;
}
