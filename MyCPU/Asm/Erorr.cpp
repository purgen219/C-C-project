#include "Erorr.h"

int my_class_error:: print_mistake(){
    cout <<"|||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << cause << " " ;
    cout << signal_int<<endl;
    cout <<function<<endl;
    cout <<file<<endl;
    cout<<line<<endl;
    cout <<"|||||||||||||||||||||||||||||||||||||||||||||||" << endl;
}
