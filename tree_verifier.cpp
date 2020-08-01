#include "tree_verifier.h"
#include <cstdint>

static bool verify_tree_path(square_graph *graph, uint16_t index, bool red_already_met);


bool verify_tree(square_graph *graph)
{
    return verify_tree_path(graph, 0, false);
}

static bool verify_tree_path(square_graph *graph, uint16_t node_index, bool red_already_met)
{
#ifndef NDEBUG
    printf("verify_tree_path: node=%u, red=%u\n", node_index, red_already_met);
#endif
    bool ret_val = true;
    for (uint16_t i = 0; i < graph->size; ++i)
    {
        if ((*graph)(node_index, i) & 0x01)
        {
#ifndef NDEBUG
            printf("Found neighbour at (%u, %u)\n", node_index, i);
#endif
            (*graph)(i, node_index) = 0;
            if ((*graph)(node_index, i) & 0x80)
            {
#ifndef NDEBUG
                printf("Neighbour %u is red\n", i);
#endif
                if (red_already_met == true)
                    return false;
                else
                    ret_val = ret_val && verify_tree_path(graph, i, true);
            }
            else
            {
                ret_val = ret_val && verify_tree_path(graph, i, false);
            }
        }
    }
    return ret_val;
}

