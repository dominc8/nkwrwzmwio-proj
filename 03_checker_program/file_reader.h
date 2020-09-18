#ifndef FILE_READER_H
#define FILE_READER_H

#include <cstdint>
#include <cassert>
#include <string>

struct square_graph
{
    uint8_t *nodes_matrix;
    uint16_t size = 0;

    uint8_t& operator()(uint16_t index);

    uint8_t& operator()(uint16_t y, uint16_t x);
};


bool read_data_from_file(square_graph *main_graph, const char* arg = nullptr);

bool does_file_exist(const std::string &user_file_path);

bool get_graph_from_file(square_graph *graph);

bool get_size_of_matrix(square_graph *graph);

bool allocate_space_for_graph(square_graph *graph);

void print_graph(square_graph *graph);


#endif /* FILE_READER_H */

