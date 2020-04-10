#ifndef MYCPU_ERORR_H
#define MYCPU_ERORR_H


#include <iostream>
#include <string>


using std::string;
using std::cout;
using std::endl;

class my_class_error{
public:
    int line;
    string function;
    string file ;
    string cause;
    int signal_int;
    int print_mistake();
    my_class_error():
        line(0),
        function("No Function"),
        file("No file"),
        cause("No cause"),
        signal_int(-1)
    {}

};

#define TEST(error , cause_str , signal_int_) \
    error.line = __LINE__;\
    error.function = __PRETTY_FUNCTION__;\
    error.file = __FILE__;\
    error.cause = cause_str;\
    error.signal_int = signal_int_


#endif
