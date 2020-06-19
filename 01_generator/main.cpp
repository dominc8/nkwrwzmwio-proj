#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <fstream>

//to visualise use thi side:
//https://graphonline.ru/en/create_graph_by_matrix

using namespace std;

class Tree{
private:
    const int max_edges_in_one_level;
    const int number_neighbors;
    int **matrix;
    int line_in_matrix;
    int column_in_matrix;

    int *red_neigbour;
    int number_red_neighbour;

    void ShowMatrix(void);
    void ClearMatrix(void);
    void CreateOneLevel(int curr_neighbors);
    void MatrixColumnUpdate(void);
    int GetMatrixColumn(void);
    void MatrixRowUpdate(void);
    int GetMatrixRow(void);
    void MatrixSymmetric(void);


public:

    Tree(int neighbors, int level_edges=10) : number_neighbors(neighbors), max_edges_in_one_level(level_edges){
        srand(time(NULL));
        //create table dynamically
        matrix = (int**)malloc((number_neighbors+1)*sizeof(int*));
        for(int i=0;i<(number_neighbors+1);++i){
            matrix[i] = (int*)malloc((number_neighbors+1)*sizeof(int));
        }
    }

    void CreateTree();
    void SaveTreeAndRandomNode(string filename);
    void GenerateRandomNumber(int percent_neighbour);
};

void Tree::ShowMatrix() {
    for(int i=0;i<number_neighbors+1;++i){
        for(int j=0;j<number_neighbors+1;++j){
            cout<< matrix[i][j]<<", ";
        }
        cout<<endl;
    }
}

void Tree::ClearMatrix(void) {
    for(int i=0;i<number_neighbors+1;++i){
        for(int j=0;j<number_neighbors+1;++j){
            matrix[i][j] = 0;
        }
    }
}

void Tree::MatrixSymmetric() {
    for(int i=0;i<number_neighbors+1;++i){
        for(int j=i;j<number_neighbors+1;++j){
            matrix[j][i] = matrix[i][j];
        }
    }
}

void Tree::CreateOneLevel(int curr_neighbors){
    //choose number edges
    int tmp;
    int edges;
    int tmp_line_matrix;
    int col_matrix = GetMatrixColumn();
    int row_matrix = GetMatrixRow();

    if(curr_neighbors == 0) {
        return;
    }

    if(curr_neighbors>max_edges_in_one_level){
        edges = rand()%max_edges_in_one_level;
    }else{
        edges = rand()%curr_neighbors;
    }

    if(edges == 0){
        edges = 1;
    }
    curr_neighbors -= edges;

    for(int i=0;i<edges;++i){
        if(i == (edges - 1)){
            matrix[row_matrix][col_matrix + i] = curr_neighbors + 1;
        }else{
            tmp = rand()%curr_neighbors;
            curr_neighbors -= tmp;
            matrix[row_matrix][col_matrix + i] = tmp + 1;
        }
        MatrixColumnUpdate();
    }

    MatrixRowUpdate();

    for(int i=0;i<edges;++i) {
        tmp = matrix[row_matrix][col_matrix + i];
        CreateOneLevel(tmp-1);
        matrix[row_matrix][col_matrix + i] = 1;
    }
}

void Tree::CreateTree() {
    line_in_matrix = 0;
    //without root
    column_in_matrix = 1;
    ClearMatrix();
    //recursion function
    CreateOneLevel(number_neighbors);
    MatrixSymmetric();
   // ShowMatrix();
}

int Tree::GetMatrixColumn() {
    return column_in_matrix;
}
void Tree::MatrixColumnUpdate() {
    ++column_in_matrix;
}

int Tree::GetMatrixRow() {
    return line_in_matrix;
}

void Tree::MatrixRowUpdate() {
    ++line_in_matrix;
}

void Tree::SaveTreeAndRandomNode(string filename) {
    fstream plik;
    string title_block;

    plik.open( filename, ios::out);
    if( plik.good() == true){

        title_block = "#Adjacency matrix\n";
        plik.write( &title_block[0], title_block.length());
        for(int i=0;i<number_neighbors+1;++i){
            for(int j=0;j<number_neighbors+1;++j){
                plik<< matrix[i][j]<<", ";
            }
            plik<<endl;
        }

        title_block = "#Red neighbour\n";
        plik.write( &title_block[0], title_block.length());
        for(int i=0;i<number_red_neighbour;++i){
            plik<< red_neigbour[i]<<", ";
        }
        plik<<endl;

        cout<<"Write data successful to "<< filename<<endl;
    }else{
        cout << "ERROR open file" <<endl;
    }
}

void Tree::GenerateRandomNumber(int percent_neighbour) {
    if((percent_neighbour < 100) && (percent_neighbour > 0)){

        number_red_neighbour = (percent_neighbour * number_neighbors) / 100;
        red_neigbour = (int*)malloc(number_red_neighbour*sizeof(int));

        for(int i=0;i<number_red_neighbour;++i){
            red_neigbour[i] = rand()%number_neighbors;
            //check repeat
            for(int j=0;j<i;++j){
                if(red_neigbour[i] == red_neigbour[j]){
                    i--;
                    break;
                }
            }
        }
    }else{
        cout<<"ERROR percent"<<endl;
    }
}

int main() {

    int count_data = 10;
    Tree tree(100, 10);
    string name_file;
    while(count_data--){
        tree.CreateTree();
        tree.GenerateRandomNumber(30);

        name_file = "tree_" + to_string(100) + "neigh_v" + to_string(count_data) + ".txt";
        tree.SaveTreeAndRandomNode(name_file);
    }

    cout << "End job" << endl;
    return 0;
}