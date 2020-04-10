#include "CPU.h"
#include "MyStack.h"

int main() {
    CPU Cpu("/home/sergey/CLionProjects/MyCPU/Asm/data_asm(exe).txt");
    try {
        MyStack<int> stack(10);
        Cpu.work_with_executable_file();
    }
    catch (my_class_error error){
        error.print_mistake();
    }
    return 0;
}