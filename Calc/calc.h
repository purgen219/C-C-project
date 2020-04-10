
#ifndef CALC_CALC_H
#define CALC_CALC_H

#include <iostream>
#include <assert.h>

typedef unsigned long long int type;


extern const int CANNOT_OPEN_FILE;
extern const int NULL_CHAR;
extern const int ERROR_SEEK;
extern const int SUCCESS;

class Calc{
public:
    const char * ptr ;
    const char * data_file;
    Calc(const char * data_file_);
    type GetG();
    type GetE();
    type GetP();
    type GetT();
    type GetN();
    type GetS();
    int r_file_w_array();
};

#endif //CALC_CALC_H
