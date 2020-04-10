#include <iostream>

using namespace std;

class my_class_error{
public:
    int line;
    string function;
    string file ;
    string cause;
};

#define TEST(error , cause_str) \
    error.line = __LINE__;\
    error.function = __PRETTY_FUNCTION__;\
    error.file = __FILE__;\
    error.cause = cause_str;

int test_func(){
    try {
        my_class_error error;
        if (true) {
            throw error;
        }
    }
    catch (my_class_error error1){
        TEST(error1, "Вот так вот");
        throw error1;
    }
}
int test_func_2(){
    try {
        test_func();
    }
    catch(my_class_error error3){
        error3.function += __PRETTY_FUNCTION__;
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
    /*try {
        test_func_2();
    }
    catch(my_class_error error){
        print_mistake (error);
    }*/
    return 0;
}