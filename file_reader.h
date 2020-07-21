#include <string>

struct square_graph
{
	uint8_t *nodes_matrix;
	uint16_t size = 0;
};

bool does_file_exist(std::string &user_file_path);

bool get_graph_from_file(struct square_graph *graph);

bool get_size_of_matrix(struct square_graph *graph);

bool allocate_space_for_graph(struct square_graph *graph);

void print_graph(struct square_graph *graph);
