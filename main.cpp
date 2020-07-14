#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include "file_reader.h"


int main(void)
{
	int ** p;
	int size = 0;
        std::vector<int> v;
        std::string user_file_path;

	while(1)
	{
		std::cout << "Please provide path to your input file:\n";
		std::cout << "(To provide default file path please type 'default')\n";
		std::cin >> user_file_path;
		if (does_file_exist(user_file_path)) break;
	}

	size = get_size_of_matrix();
	p = allocate_space_for_graph_matrix(size);
	extract_graph_from_file(p, size, v);
	print_graph_matrix_and_neighbours(p, size, size, v);

	delete[] p;
	return 0;
}
