#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
#include <stdint.h>
#include <algorithm>
#include "file_reader.h"


uint8_t& square_graph::operator()(uint16_t index)
{
    assert(index < size*size);
    return nodes_matrix[index];
}

uint8_t& square_graph::operator()(uint16_t y, uint16_t x)
{
    assert(y*size + x < size*size);
    return nodes_matrix[y*size + x];
}


using namespace std;

static string file_path;
static string default_file_path = "./02_sample_data/10Neighbours_30PercentRed/tree_10neigh_v0.txt";

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool read_data_from_file(square_graph *main_graph, const char* arg)
{
    string user_file_path;


    if (arg != nullptr && !does_file_exist(arg))
    {
        arg = nullptr;
    }


    if (arg == nullptr)
    {
        /* Get filepath from user and check if it exists */
        while(1)
        {
            cout << "Please provide path to your input file:" << endl;
            cout << "(To provide default file path please type 'default')" << endl;

            cin >> user_file_path;

            if (does_file_exist(user_file_path))
                break;
        }
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
        cout << "Getting data from file failed!" << endl;
        return false;
    }

    cout << "Graph read succesfully!" <<endl;

    return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool does_file_exist(const string &user_file_path)
{
    string line;

    /* User used default */
    if (user_file_path == "default")
    {
        cout << "User didn't provide any path.\n";
        cout << "Using default path: " << default_file_path << '\n';
        file_path = default_file_path;
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

bool get_graph_from_file(square_graph *graph)
{
    string tmp;
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

        while (one_index != string::npos)
        {
            (*graph)(i, one_index) = 0x01;
            one_index = tmp.find_first_of('1', one_index + 1);
        }

        getline(file_stream, tmp);
    }

    /* Read and set neighbours nodes */
    getline(file_stream, tmp);

    tmp.erase(remove(tmp.begin(), tmp.end(), ' '), tmp.end());
#ifndef NDEBUG
    cout << "Red vertices: " << tmp << endl;
#endif

    int start_index = 0;

    for (int k = 0; k < tmp.length(); ++k)
    {
        char number = tmp[k];

        if (number == ',')
        {
            int neighbour_index = std::strtol(tmp.c_str() + start_index, nullptr, 0);

            for (int i = 0; i < graph->size; ++i)
            {
                if ((*graph)(i, neighbour_index) == 0x01)
                {
                    (*graph)(i, neighbour_index) = 0x81;
                }
            }

            start_index = k + 1;
        }
    }
    return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool allocate_space_for_graph(square_graph *graph)
{
    graph->nodes_matrix = new (nothrow) uint8_t [graph->size * graph ->size];

    if(graph->nodes_matrix == NULL)
        return false;

    memset(graph->nodes_matrix, 0, graph->size * graph->size * sizeof(uint8_t));

    return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void print_graph(square_graph *graph)
{
    /* Printing graph matrix */
    cout << "Number of vertices: " << graph->size << endl;
    cout << "Graph matrix:" << endl;

    for (int i = 0; i < graph->size; ++i)
    {
        for (int j = 0; j < graph->size; ++j)
        {
            cout << (int)(*graph)(i, j) << " ";
        }

        cout << endl;
    }

    cout << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool get_size_of_matrix(square_graph *graph)
{
    string tmp;

    /* Opening file */
    ifstream file_stream;

    file_stream.open(file_path);

    /* Skip first line */
    getline(file_stream, tmp);

    /* Get first line, and check matrix size*/
    getline(file_stream, tmp);

    size_t last_element_index = max(tmp.find_last_of('0'), tmp.find_last_of('1'));

    /* Set right size of matrix */
    if (last_element_index == string::npos)
        return false;

    graph->size = (uint16_t)(last_element_index/3 + 1);

    return true;
}

