#ifndef  Head_Stack

#define BAD_ELEM -1
#define BAD_CAPACITY -2

using namespace std;

class MyStack{
private:
    string * array ;
    int size ;
    int capasity;
public:
    MyStack(int cap_):
        array(new string[1]), // указатель на массив в стеке . он же шапка стека
        size(0), // размер в каждый момент
        capasity(1) // максимальный размер
    {
        if (cap_>0){
            capasity = cap_;
            array = new string [cap_];
        }

    }
    ~MyStack(){
        delete[] array;
    };
    int size_(){
        return size;
    }
    int capasity_(){
        return capasity;
    }
    int push(string *  string1){
        if (size < capasity) {
            *(array + size) = *string1;
        }
        else{
            array = my_realloc();
            cout << capasity;
            *(array + size) = *string1;
        }
        size++;
        if (size == capasity){
            array = my_realloc();
        }
        return EXIT_SUCCESS;
    }
    int pop(){
        if (size == 0){
            return EXIT_SUCCESS;
        }
        else{
            *(array + size) = "null_string";
            size--;
        }

    }
    string * my_realloc(){
        string * help_array = new string [capasity*2];
        if (size == 0){

        }
        for (int i = 0 ;i < capasity ; i++){
            help_array[i] = array[i];
        }
        for (int i = capasity ; i<capasity*2 ; i++){
            help_array [i] = "null_string";
        }
        capasity = capasity*2;
        return help_array;
    }
    string top() {
        if (size <= 0){
            return "stack_pust";
        }
        return *(array + size-1);
    }
};

#endif