default:
	rm -f log
	g++ -DNDEBUG file_reader.cpp main.cpp -o main

debug:
	rm -f log
	g++ file_reader.cpp main.cpp -o main


