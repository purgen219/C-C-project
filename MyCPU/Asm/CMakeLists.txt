cmake_minimum_required(VERSION 3.12)
project(MyCPU)

set(CMAKE_CXX_STANDARD 14)

add_executable(MyCPU main.cpp Const.h Asm.h Erorr.h Erorr.cpp Asm.cpp)
