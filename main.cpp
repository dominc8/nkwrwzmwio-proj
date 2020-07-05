#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include "file_reader.cpp"

#define DEBUG_MODE 1;

string user_file_path;

using namespace std;

int main(int argc, char const *argv[])
{
	while(1)
	{
		cout << "Please provide path to your input file:" << endl;
		cin >> user_file_path;
		if (does_file_exist(user_file_path)) break;
	}

	int ** p;
	p = extract_graph_from_file(user_file_path);
	delete[] p;
	return 0;
}