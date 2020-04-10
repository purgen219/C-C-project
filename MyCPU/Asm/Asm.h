#ifndef MYCPU_ASM_H
#define MYCPU_ASM_H

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

extern int EMPTY ;
extern int EMPTY_POP ;

extern int ASCII ;

extern int SUCCESS ;
extern int CANNOT_OPEN_FILE ;
extern int NULL_CHAR ;
extern int ERROR_SEEK ;

#include "Erorr.h"
#include "Const.h"

class semantic_piece{ // Структура с кодом функции и аргументом
public:
    int  code_func;
    int  code_arg;
    semantic_piece():
            code_func(EMPTY),
            code_arg(EMPTY)
    {}
};
class label_ptr { // Метка и адрес
public:
    string label;
    int ptr;
    label_ptr():
            label("no_label"),
            ptr(-1)
    {}
};
class func_ptr { // функция и адрес
public:
    string func;
    int ptr;
    func_ptr():
            func("no_func"),
            ptr(-1)
    {}
};

class Asm{
public:
    char * data_file;
    char * executable_file;
    int chr ;
    int nstr;
    vector<char> text;
    vector<char> buf;
    vector<string> tokens ;
    vector<label_ptr> vector_label;
    vector<func_ptr> vector_func;
    vector<semantic_piece> func_arg;
    vector<int> array_code;
    Const constant;

    Asm(char * data_file_,char * executable_file_):
            data_file(data_file_),
            executable_file(executable_file_),
            chr(0),
            nstr(0)
    {}

    ////WORK_WITH_FILE////
    int r_file_w_array ();
    int create_array_data();
    int create_array_for_exe_file();
    int create_executable_file();
    ////TOKEN////////////
    int Tokenization();
    int get_number (const string & str_number );
    int it_is_number(string number);
    /////LOGIC///////////
    int create_semantic_peace() ;
    int create_array_label_and_function();
};


#endif //MYCPU_ASM_H
