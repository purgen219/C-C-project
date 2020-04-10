#ifndef MYCPU_ERORR_H
#define MYCPU_ERORR_H

#define STATICK_SIZE 15

#include <iostream>
#include <string>
#include <assert.h>

extern int error_index;

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
    my_class_error():
        line(0),
        function("No Function"),
        file("No file"),
        cause("No cause"),
        signal_int(-1)
    {}

};

int print_mistake(const my_class_error * array_error  );


#define TEST(error , cause_str , signal_int_ ) \
    error.line = __LINE__;\
    error.function = __PRETTY_FUNCTION__;\
    error.file = __FILE__;\
    error.cause = cause_str;\
    error.signal_int = signal_int_;\
    //array_error[error_index] = error;\
    error_index ++;\
    if (error_index == STATICK_SIZE)\
        assert(0);

#endif
