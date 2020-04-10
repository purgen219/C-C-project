
#ifndef CPU_MYSTACK_H
#define CPU_MYSTACK_H

#include <iostream>
#include <string>

#include "Erorr.h"

using std::cout;


template <typename T>
class MyStack{
private:
    T * array;
    int size;
    int capasity;
public:
    explicit MyStack(int cap_);
    ~MyStack();
    int size_();
    int capasity_();
    int push(T * elem1);
    T pop();
    T * my_realloc();
};

#endif //CPU_MYSTACK_H
