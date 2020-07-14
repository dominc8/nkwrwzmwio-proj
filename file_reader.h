#include <vector>
#include <string>

bool does_file_exist(const std::string &user_file_path);
bool extract_graph_from_file(int **graph_matrix, int matrix_size, std::vector<int> &neighbours_v);
int ** allocate_space_for_graph_matrix(int matrix_size);
void print_graph_matrix_and_neighbours(int ** in_graph, int rows, int columns, std::vector<int> &in_neighbours);
int get_size_of_matrix();

