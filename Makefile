SRC := file_reader.cpp tree_verifier.cpp main.cpp


default:
	g++ -Ofast -DNDEBUG $(SRC) -o main

debug:
	g++ $(SRC) -o main

