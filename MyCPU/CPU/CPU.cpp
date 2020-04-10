#include "CPU.h"


int EMPTY = -666;


int CPU::work_with_executable_file(){ // обработка и вызов функций сделать
    try {
        int size = 0;
        my_class_error error;
        FILE *file = fopen(executable_file, "rb");
        if (!file) {
            TEST(error,"Нифига не открылось.",0);
            throw error;
        }
        fread(&size, sizeof(int),1,file);
        array_code = new int[size];
        fread( array_code, sizeof(int), size , file);
        fclose(file);
        for (int j=0 ; j <size ; j++){
            cout << *(array_code+j) << endl;
        }
    }
    catch (my_class_error error){
        throw error;
    }
}
