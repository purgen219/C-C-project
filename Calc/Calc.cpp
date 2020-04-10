#include "calc.h"

const int CANNOT_OPEN_FILE = -1;
const int NULL_CHAR = -2;
const int ERROR_SEEK = -3;
const int SUCCESS = 0;

Calc::Calc(const char *data_file_) :
        ptr(nullptr),
        data_file(data_file_)
        {}
type Calc:: GetG(){
    type val = GetE();// перекладывание ответственности
    assert(*ptr == ';');//конец строчки
    ptr++;
    return val;
}
type Calc::GetE(){
    type val = GetT(); // вызывает N-ку ,если начинается с числа . Прошлое должно включаться в будущее
    const char * operand = nullptr;
    while(*ptr == '+' || *ptr == '-' ){
        operand = ptr;
        ptr++;
        type val2 = GetT();
        if (*operand == '+'){
            val+=val2;
        }
        if (*operand == '-'){
            val-=val2;
        }
    }
    return val;
}
type Calc::GetP(){
    type val = 0 ;
    if (*ptr == '(' ){
        ptr++;
        val = GetE();
        assert(*ptr == ')');
        ptr++;
    }
    else{
        val = GetN();
    }
    return val;
}
type Calc::GetT(){
    type val = GetS();
    type val2 = 0;
    const char * operand = ptr;
    while (*ptr == '*' || *ptr == '/'){
        ptr++;
        val2 = GetS();
        if (*operand == '*' ){
            val = val*val2;
        }
        if (*operand == '/'){
            val = val/val2;
        }
    }
    return val;
}
type Calc:: GetN(){
    type val = 0;
    const char * sav_ptr = ptr;
    while('0'<= *ptr && *ptr <= '9' ){
        val = val*10 + (*ptr - '0');
        ptr++;
    }
    assert(ptr>sav_ptr); // чтоб цикл сделал как мнимум один оборот
    return val;
}
///FILE///
type Calc:: GetS(){
    type val = GetP();
    type result = val;
    while (*ptr == '^') {
        ptr++;
        type val2 = GetS();
        if (val2 > 0) {
            for (int i = 1; i < val2; i++) {
                val = val * result;
            }
        }
        else if (val2 == 0){
            val=1;
        }
        else if (val2 < 0){

        }
    }
    return val;
}
int Calc::r_file_w_array (){
    FILE* file=fopen(data_file, "r");
    if (!file){
        printf("Cannot open %s\n" , data_file);
        return CANNOT_OPEN_FILE;
    }
    fseek(file,0,SEEK_END);
    int chr = ftell(file);
    if (chr == 0){
        printf("null char");
        return NULL_CHAR;
    }
    fseek( file , 0 , SEEK_SET );
    int seek  = ftell(file);
    if (seek != 0){
        printf("Bad SEEK_SET");
        return ERROR_SEEK;
    }
    char * text = (char *) calloc (sizeof(char),chr);
    fread (text , sizeof(char) , chr , file);
    ptr = text;
    //printf("%s",text);
    fclose(file);
    return SUCCESS ;
}