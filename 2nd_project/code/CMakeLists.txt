cmake_minimum_required(VERSION 3.20)
project(aed2122_trabalho2)

set(CMAKE_CXX_STANDARD 14)

add_executable(aed2122_trabalho2 ./src/main.cpp ./src/graph.cpp ./include/graph.h ./include/minHeap.h ./include/disjointSet.h)
