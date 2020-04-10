#include <iostream>

using namespace std;

class my_class_error{
public:
    int line;
    char * function;
    char * file ;
    char * cause;
        my_class_error():
            line(-1),
            function(nullptr),
            file(nullptr),
            cause(nullptr)
        {}
        my_class_error(char * cause_):
            line(-1),
            function(nullptr),
            file(nullptr),
            cause(cause_)
        {}
        my_class_error(char * cause_, char * function_ ):
            line(-1),
            function(function_),
            file(nullptr),
            cause(cause_)
        {}
        my_class_error(char * cause_, char * function_ ,char * file_):
                line(-1),
                function(function_),
                file(file_),
                cause(cause_)
        {}

        my_class_error(char * cause_, char * function_ ,char * file_,int line_):
                line(line_),
                function(function_),
                file(file_),
                cause(cause_)
        {}
};

#define TEST(msg,...) \
    my_class_error error(msg , #__VA_ARGS__);

int test_func(){
    try {
        my_class_error error;
        if (true) {
            throw 1;
        }
    }
    catch (...){
        TEST("тут вообще пиздец",__PRETTY_FUNCTION__);
        throw error;
    }
}
int test_func_2(){
    try {
        test_func();
    }
    catch(my_class_error error3){
        throw error3;
    }
}
int print_mistake(my_class_error error){
    cout << error.cause<<endl;
    cout <<error.function<<endl;
    cout <<error.file<<endl;
    cout<<error.line<<endl;
}
int main() {
    try {
        test_func_2();
    }
    catch(my_class_error error){
        print_mistake (error);
    }
    return 0;
}