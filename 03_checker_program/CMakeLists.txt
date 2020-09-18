cmake_minimum_required(VERSION 3.15)
project(03_checker_program)

set(CMAKE_CXX_STANDARD 14)

add_executable(03_checker_program main.cpp file_reader.cpp file_reader.h tree_verifier.cpp tree_verifier.h)