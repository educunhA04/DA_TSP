cmake_minimum_required(VERSION 3.26)
project(DA_TSP)

set(CMAKE_CXX_STANDARD 17)

add_executable(DA_TSP main.cpp
        MutablePriorityQueue.h
        Menu.cpp
        Menu.h
        Menu.cpp
        Graph.cpp
        Graph.h
        GraphInterface.cpp
        GraphInterface.h
        Parser.cpp
        Parser.h
        GraphInterface.cpp)
