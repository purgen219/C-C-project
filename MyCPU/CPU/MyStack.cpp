#include "MyStack.h"


template <typename T>
MyStack<T> :: MyStack(int cap_):
        array(nullptr), // указатель на массив в стеке . он же шапка стека
        size(0), // размер в каждый момент
        capasity(1) // максимальный размер
{
    try {
        if (cap_ > 0) {
            capasity = cap_;
            array = new T[cap_];
        } else {
            my_class_error error;
            TEST(error,"Что за фигню ты сунул в размер :" , cap_ );
            throw error;
        }
    }
    catch (my_class_error error){
        throw error;
    }

}
template <typename T>
MyStack<T> :: ~MyStack(){
    delete[] array;
}
template <typename T>
int MyStack<T> :: size_(){
    return size;
}
template <typename T>
int MyStack<T> :: capasity_(){
    return capasity;
}
template <typename T>
int MyStack<T> :: push(T * elem1){
    if (size < capasity) {
        *(array + size) = *elem1;
    }
    else{
        array = my_realloc();
        cout << capasity;
        *(array + size) = *elem1;
    }
    size++;
    if (size == capasity){
        array = my_realloc();
    }
    return EXIT_SUCCESS;
}
template <typename T>
T  MyStack<T> :: pop(){
    if (size == 0){
        return EXIT_SUCCESS;
    }
    else{
        size--;
        return *(array+size+1);
    }

}
template <typename T>
T * MyStack<T> :: my_realloc(){
    T * help_array = new T [capasity*2];
    if (size == 0){

    }
    for (int i = 0 ;i < capasity ; i++){
        help_array[i] = array[i];
    }
    capasity = capasity*2;
    return help_array;
}
/*T top() {
    if (size <= 0){
        return "stack_pust";
    }
    return *(array + size-1);
}*/
