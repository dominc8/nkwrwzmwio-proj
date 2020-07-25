#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include "file_reader.h"

int main(int argc, char const *argv[])
{
    square_graph main_graph;

    if (!read_data_from_file(&main_graph))
        return -1;

    print_graph(&main_graph);

    delete[] main_graph.nodes_matrix;

    return 0;
}

