cmake_minimum_required(VERSION 3.12)
project(Hash_table)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Hash_table
        Hash_table.cpp
        Hash_table.h)
