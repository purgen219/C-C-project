#include <iostream>
#include "calc.h"
#include <byteswap.h>
#include <stdio.h>


int main() {
    printf("%x",bswap_16(32769));
    /*
    Calc calc("/home/sergey/CLionProjects/Calc/Exemple");
    calc.r_file_w_array();
    type val = calc.GetG();
    printf("%u\n",val);
    printf("%d\n", sizeof(int *));
    //printf("%s",ptr);
    return 0;
     */
}