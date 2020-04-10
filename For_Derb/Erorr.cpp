#include "Erorr.h"

int error_index = 0;

int print_mistake(const my_class_error * array_error  ){
    for (int i = 0 ; i<error_index ; i++) {
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << array_error[i].cause << " ";
        cout << array_error[i].signal_int << endl;
        cout << array_error[i].function << endl;
        cout << array_error[i].file << endl;
        cout << array_error[i].line << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    }
    return 0;
}
