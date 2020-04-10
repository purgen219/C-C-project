#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Erorr.h"
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int ASCII = 48;

const char * data_txt = "/home/sergey/CLionProjects/For_Derb/data_test.txt";
my_class_error array_error[STATICK_SIZE];

class tokens{
public:
    int number_comand ;
    int address_in_array ;
        tokens():
            number_comand(0),
            address_in_array(0)
        {}
};
vector <tokens> array_tokens;

int  work_with_file(){
    FILE *file = fopen(data_txt, "r");
    tokens help;
    int i = 0 ;
    while (fscanf(file,"%d",&(help.number_comand)) != EOF){
        help.address_in_array = i;
        array_tokens.push_back(help);
        if ( i == 5 ){
            i=i+4;
        }
        i++;

    }
    cout << array_tokens.size() << endl;
    for (int i= 0; i< array_tokens.size() ; i++){
        cout << array_tokens[i].address_in_array << " ";
        cout << array_tokens[i].number_comand << endl;
    }
}
bool is_it_number(int i){
    int k = 4 ;
    while (i != k){
        if ( k > 100){
            break;
        }
        k = k+10;
    }
    if (i == k){
        return true;
    }
    if (i != k){
        return false;
    }
}
int get_number (vector<int> number ){
    int size = number.size();
    int count = 0;
    int help_number = 0;
    for (int i = 0 ; i < size ; i++){
        help_number = pow(10,i);
        count = (number[size-i-1]) * help_number + count ;
    }
    return count;
}
double create_number (int ip){
    vector <int> number1 ;
    vector <int> number2 ;
    int ch = 0 ;
    do {
        if(array_tokens[ip].number_comand != 46 ) {
            ch = (array_tokens[ip].number_comand / 10);
            number1.push_back(ch);
            ip++;
        }
        else{
            ip++;
            while (is_it_number(array_tokens[ip].number_comand)){
                ch = (array_tokens[ip].number_comand / 10);
                number2.push_back(ch);
                ip++;
            }
        }
    }while (is_it_number(array_tokens[ip].number_comand) || array_tokens[ip].number_comand == 46 );
    int result1 = get_number(number1);
    int result2 = get_number(number2);
    double result = result1 + (result2)/(pow(10,number2.size())) ;
    cout << "{" << ip << "}";
    return result;
}
int main() {
    work_with_file();
    cout << create_number(0) << endl;
}