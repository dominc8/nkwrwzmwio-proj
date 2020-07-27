SRC := file_reader.cpp tree_verifier.cpp main.cpp


default:
	rm -f log
	g++ -DNDEBUG $(SRC) -o main

debug:
	rm -f log
	g++ $(SRC) -o main


