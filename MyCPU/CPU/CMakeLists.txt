cmake_minimum_required(VERSION 3.12)
project(CPU)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPU main.cpp Erorr.cpp Erorr.h CPU.cpp CPU.h MyStack.h MyStack.cpp)