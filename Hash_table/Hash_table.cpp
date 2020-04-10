#include "Hash_table.h"


struct Node {
    info_string data;
    Node * next;
    Node * prev;
    Node ():
            data(),
            next(nullptr),
            prev(nullptr)
    {}
    ~Node(){};
};

class List {
public:
    size_t size;
    Node * head;
    Node * tail;
    List():
            size (0),
            head (nullptr),
            tail (nullptr)
    {}
    ~List(){};
    int find (Node * node) {
        Node * head_ = head;
        int size_=size;
        if (size == 0){
            return ELEM_NOT_IN_LIST;
        }

        while (head_ != nullptr) {
            if (strcmp(node->data.text_ptr, head_->data.text_ptr) == 0) {
                return ELEM_IN_LIST;
            }
            else {head_ = head_ ->next ;}
        }
        return ELEM_NOT_IN_LIST;
    }
    /*int push_back( Node * node) {
        if (size == 0) {
            head = node;
            tail = node;
            size++;
        }
        if (find(node) == ELEM_IN_LIST){
            return SUCCESS;
        }

        else {
            tail->next = node;
            node->next = nullptr;
            node->prev = tail;
            tail = node;
            size++;
        }
        return SUCCESS;
    }*/
    int push_front ( Node * node ) {
        if (!node ){
            return BAD_NODE;
        }
        if ( size== 0){
            tail = node ;
            head = node ;
            size++;
        }
        else {
            node->next = head;
            node->next -> prev = node;
            head = node;
            node->prev = nullptr;
            size++;
        }
    }
    int pop_front  (){
        if ( size== 0){
            return SUCCESS;
        }
        if ( size == 1){
            head = nullptr;
            tail = nullptr;
            free(tail);
        }
        else {
            head =head -> next;
            head -> prev -> next = nullptr;
            free(head->prev);
            head -> prev = nullptr;
        }
        size--;
        return SUCCESS ;
    }
    int pop_back (){
        if ( size == 0){
            return SUCCESS;
        }
        if ( size == 1){
            free( tail);
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail=tail -> prev;
            //free(tail->next); //вернуться
            tail -> next = nullptr;
        }
        size --;
        return SUCCESS ;
    }

    int Delete (Node * node ){
        if (!node ){
            return BAD_NODE;
        }
        if (node -> prev == nullptr){
            pop_front();
        }
        else if (node -> next == nullptr ){
            pop_back();
        }
        else {
            node -> next -> prev = node -> prev ;
            node -> prev -> next = node -> next ;
            size --;
            node -> next = nullptr ;
            node -> prev = nullptr ;
            free (node);
        }
        return SUCCESS;
    }

public:
    int size_l (){
        return size;
    }
    int Find_Delete (Node * node){
        if (find(node)==ELEM_IN_LIST){
            Delete(node);
            return SUCCESS1;
        }
        if (find(node)==ELEM_NOT_IN_LIST){
            return SUCCESS2;
        }
    }
    int Find_Insert (Node * node){
        if (find(node)==ELEM_IN_LIST){
            return SUCCESS3;
        }
        else if (find(node)==ELEM_NOT_IN_LIST){
            push_front(node);
            return SUCCESS4;
        }
    }
    int print_node (){
        int i =0;
        if ( size == 0){
            return NO_ELEMENT_IN_LIST;
        }
        else{
            while (head != nullptr){
                printf("node %d = %s \n" ,size-i, head -> data  ); // печатать все
                i++;
                head = head -> next ;
            }
        }
        return SUCCESS;
    }
};
class HashTable {
public:
    List array_list[STATIC_SIZE];
    int  (* hash_func)(Node &);
    explicit HashTable (int (*func)(Node &)):
            array_list(),
            hash_func(func)
    {}
    int  Filling(Node ** array_node, int nstr){
        for (int i = 0 ; i < nstr ; i++) {
            int index = (hash_func(*((*array_node)+i)))%(STATIC_SIZE);
            if (index < 0){
                index = (-1)*index;
            }
            //printf(" %d\n",index);
            array_list[index].Find_Insert((*array_node)+i);
        }
    }
    int Unfilling(Node ** array_node , int nstr){
        for (int i = 0 ; i < nstr ; i++) {
            int index = (hash_func(*((*array_node)+i)))%(STATIC_SIZE);
            if (index < 0){
                index = (-1)*index;
            }
            //printf(" %d\n",index);
            array_list[index].Find_Delete((*array_node)+i);
        }
    }
    int W_In_File (char * filename ){
        FILE * file = fopen(filename,"w");
        for (int i=0 ; i<STATIC_SIZE;i++){
            fprintf(file," %d\n",array_list[i].size_l());
        }
        fclose(file);
    }

};
int hash_1(Node & node){
    return (int) *(node.data.text_ptr);
}

int hash_2(Node & node){
    return node.data.string_length;
}

int hash_3(Node & node){
    int sum_of_letters = 0;
    for(int i = 0; i < node.data.string_length; i++){
        sum_of_letters += (int) *(node.data.text_ptr+i);
    }
    return sum_of_letters ;
}

int Create_array_node(info_string * array_struct , Node ** array_node , int nstr){
    *array_node = new Node[nstr];
    for (int i = 0 ; i<nstr ; i++){
        (*array_node+i)->data = array_struct[i];
    }

}

//......................//
int main() {
    /*.................................*/

    info_string * array_struct = new info_string () ;
    Node * array_node = new Node() ;
    char * text = nullptr;
    int chr = 0;
    HashTable table1(hash_1);
    HashTable table2(hash_2);
    HashTable table3(hash_3);

    /*.................................*/
    int nstr = r_file_do_array_str("/home/sergey/CLionProjects/Hash_table/Onegin",&array_struct);
    Create_array_node(array_struct,&array_node,nstr);
    table1.Filling(&array_node, nstr);
    table2.Filling(&array_node, nstr);
    table3.Filling(&array_node, nstr);
    table1.W_In_File("/home/sergey/CLionProjects/Hash_table/Result_hash1");
    table2.W_In_File("/home/sergey/CLionProjects/Hash_table/Result_hash2");
    table3.W_In_File("/home/sergey/CLionProjects/Hash_table/Result_hash3");
    /*table1.Unfilling(&array_node, nstr);
    for (int i=0 ; i<STATIC_SIZE;i++){
        printf("index_new = %d ; quantity_new = %d\n",i,table1.array_list[i].size_l());
    }*/

    return 0;
}