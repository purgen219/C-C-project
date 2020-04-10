#ifndef MYCPU_CPU_H
#define MYCPU_CPU_H

#include <vector>
#include <iostream>
#include <string>

extern int EMPTY;

#include "Erorr.h"
#include "MyStack.h"

class semantic_piece{ // Структура с кодом функции и аргументом
public:
    int  code_func;
    int  code_arg;
    semantic_piece():
            code_func(EMPTY),
            code_arg(EMPTY)
    {}
};

class CPU{
public:
    const char * executable_file;
    int * array_code;

    int sp;
    int bp;

    int ax;
    int bx;
    int cx;
    int dx;

    CPU(const char * executable_file_):
        executable_file(executable_file_),
        array_code(nullptr)
    {}
    int work_with_executable_file();

};

#endif

#include "MyStack.cpp"