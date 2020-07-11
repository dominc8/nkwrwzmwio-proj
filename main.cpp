#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include "file_reader.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
	int ** p;
	int size = 0;
	vector<int> v;
	string user_file_path;

	while(1)
	{
		cout << "Please provide path to your input file:" << endl;
		cout << "(To proviade default file path please tpye 'default')" << endl;
		cin >> user_file_path;
		if (does_file_exist(user_file_path)) break;
	}

	size = get_size_of_matrix();
	p = allocate_space_for_graph_matrix(size);
	extract_graph_from_file(p, size, v);
	print_graph_matrix_and_neighbours(p, size, size, v);

	delete[] p;
	return 0;
}