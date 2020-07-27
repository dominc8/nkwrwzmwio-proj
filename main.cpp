#include <cstdio>
#include "file_reader.h"
#include "tree_verifier.h"


int main(int argc, char const *argv[])
{
    int ret_val = 0;
    square_graph main_graph;
    const char* filename = NULL;

    if (argc == 2)
    {
        filename = argv[1];
    }

    if (!read_data_from_file(&main_graph, filename))
    {
        return -1;
    }

    print_graph(&main_graph);

    if (verify_tree_paths(&main_graph) == true)
    {
        printf("Tree paths are good!\n");
    }
    else
    {
        printf("Tree paths are bad!\n");
        ret_val = 1;
    }

    delete[] main_graph.nodes_matrix;

    return ret_val;
}

