#include "Asm.h"

int main() {
    Asm Asm("/home/sergey/CLionProjects/MyCPU/Asm/data_asm.txt", "/home/sergey/CLionProjects/MyCPU/Asm/data_asm(exe).txt");
    try {
        Asm.r_file_w_array();
        Asm.create_array_data();
        Asm.Tokenization();
        Asm.create_array_label_and_function();
        Asm.create_semantic_peace();
        Asm.create_array_for_exe_file();
        Asm.create_executable_file();
    }
    catch (my_class_error error){
        error.print_mistake();
    }
    return 0;
}