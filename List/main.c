#include <stdio.h>
#include <stdlib.h>
//
#define ERROR_PTR -1
#define ERROR_CANARY -4
#define ERROR_CHECKSUM -5
#define SUCCESS 1000
#define CANARY 230
#define CANARY_LIST 231
#define ELEM_IN_LIST  -8
#define NO_ELEMENT_IN_LIST -9
#define ERROR_PTR_IN_LIST -10
#define ERROR_CANARY_IN_LIST -11
#define ERROR_CHECKSUM_IN_LIST -12
#define ERROR_CHECK_DATA_IN_LIST -13
#define ELEM_OUT_LIST -14
#define BAD_ELEM_FOR_PRINT -15
#define BAD_NODE_ID -16
#define BAD_LIST_ID -17


#define _(cmd) \
{\
print_mistake(cmd);\
}\

#define OK( what )\
{\
int res = what;\
if (res != SUCCESS){\
    return res ;\
    }\
}\

typedef int type_t;
//
typedef struct Node_t {
    int canary1;
    type_t data;
    struct Node_t *next;
    struct Node_t *prev;
    long checksum;
    int canary2;
} Node;
typedef struct List_t {
    int canary1;
    type_t data;
    struct Node_t *head;
    struct Node_t *tail;
    long check_data;
    long checksum;
    int canary2;
} List;

//
long CreateList(); // for user

long CreateNode(type_t data); // for user

int Ok_node(Node *node);

int Ok_list(List *list);

int F_checksum_node(Node *node);

int F_check_list(List * list);

int push_back(long list, long node); // for user

int pop_back (long list_id );// for user

int print_node (long  node , long list );// for user

List * Decoding_list (long list_id );

Node * Decoding_node (long node_id );

long Encoding_list (List * list );

long Encoding_node (Node * node );

int push_front ( long  list_id , long node_id );// for user

void print_mistake (int cod_mistake );// for user (Use macros )

int Check_elem_in_list (Node * node , List * list );

int Check_elem_out_list (Node * node , List * list );

int pop_front  (long list_id );// for user

int Insert_after (long node_id , long node_id_new , long list_id);// for user

int Delete (long node_id , long list_id);// for user

int Delete_all (long list_id );// for user


//
int main() {
    long node = CreateNode(1);
    long node_1 = CreateNode(2);
    long list = CreateList();

    _(push_front(list , node ));
    _(push_front(list , node_1 ));

    _(print_node(node_1 , list));

    return 0;
}

//
long CreateNode(type_t data) {
    Node * node = (Node *) calloc(1, sizeof(Node));
    node->canary1 = CANARY;
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    F_checksum_node(node);
    node->canary2 = CANARY;
    return Encoding_node(node);

}

//
long CreateList() {
    static int count = 0;
    if (count == 0) {
        List *list = (List *) calloc(1, sizeof(List));
        list->canary1 = CANARY_LIST;
        list->data = 0;
        list->head = NULL;
        list->tail = NULL;
        list->canary2 = CANARY_LIST;
        F_check_list(list);
        count++;
        return Encoding_list(list);
    }

}

//
int pop_back (long  list_id ){
    List * list = Decoding_list(list_id);
    if (!list ){
        return BAD_LIST_ID;
    }
    OK(Ok_list (list));
    //
    if ( list->data == 0){
        return SUCCESS;
    }
    if ( list->data == 1){
        free(list -> tail);
        list -> head = NULL;
        list -> tail = NULL;
    }
    else {
        list -> tail=list -> tail -> prev;
        free(list->tail->next);
        list -> tail -> next = NULL;
        F_checksum_node (list -> tail) ;
        OK(Ok_node (list -> tail)) ;
    }
    list->data = list->data - 1;
    F_check_list (list) ;
    //
    OK(Ok_list (list)) ;
    return SUCCESS ;
}

//
int push_back(long list_id, long node_id) {
    Node * node = Decoding_node(node_id);
    if (!node ){
        return BAD_NODE_ID;
    }
    List * list = Decoding_list(list_id);
    if (!list ){
        return BAD_LIST_ID;
    }
    //
    OK(Ok_node(node));
    OK(Ok_list(list));
    OK(Check_elem_in_list(node,list));
    //
    if (list->data == 0) {
        list->head = node;
        list->tail = node;
        list->data = (list->data) + 1;
    }
    else {
        (list->tail)->next = node;
        node->next = NULL;
        node->prev = list->tail;
        list->tail = node;
        list->data = (list->data) + 1;
        F_checksum_node(node->prev);
        OK(Ok_node(node->prev));
    }
    F_check_list(list);
    F_checksum_node(node);
    //
    OK(Ok_list(list));
    OK(Ok_node(node));
    return SUCCESS;
}

//
int push_front ( long  list_id , long node_id ) {
    Node * node = Decoding_node(node_id);
    if (!node ){
        return BAD_NODE_ID;
    }
    List * list = Decoding_list(list_id);
    if (!list ){
        return BAD_LIST_ID;
    }
    OK(Ok_list(list));
    OK(Ok_node(node));
    OK(Check_elem_in_list(node,list));
    //......................//
    if (list -> data == 0){
        list -> tail = node ;
        list -> head = node ;
        list->data = (list->data) + 1;
    }
    else {
        node->next = list-> head;
        node->next -> prev = node;
        list-> head = node;
        node->prev = NULL;
        list->data = list->data + 1;
        F_checksum_node(node->next);
        OK(Ok_node(node->next));
    }
    F_check_list( list );
    F_checksum_node( node );
    //.......................//
    OK(Ok_node ( node ));
    OK(Ok_list ( list ));

}

//
int pop_front  (long list_id ){
    List * list = Decoding_list(list_id);
    if (!list ){
        return BAD_LIST_ID;
    }
    OK(Ok_list (list));
    //
    if ( list->data == 0){
        return SUCCESS;
    }
    if ( list->data == 1){
        free(list -> tail);
        list -> head = NULL;
        list -> tail = NULL;
    }
    else {
        list -> head = list -> head -> next;
        list -> head -> prev -> next = NULL;
        free(list->head->prev);
        list -> head -> prev = NULL;
        F_checksum_node (list -> head) ;
        OK(Ok_node (list -> head)) ;
    }
    list->data = list->data - 1;
    F_check_list (list) ;
    //
    OK(Ok_list (list)) ;
    return SUCCESS ;
}

//
int F_checksum_node(Node * node) {
    node->checksum = (182 * ((long) node->next) + 17 * ((long) (node->prev)) + 291) % 1274;
}

//
int Ok_list(List * list) {
    if (list == NULL) {
        return ERROR_PTR_IN_LIST;
    }
    if (list->canary1 != CANARY_LIST || list->canary2 != CANARY_LIST) {
        return ERROR_CANARY_IN_LIST;
    }
    if (list->checksum != (182 * (long) (list->tail) + 17 * (long) (list->head) + 291) % 1274) {
        return ERROR_CHECKSUM_IN_LIST;
    }
    if (list->check_data != 5 * (list->data) + 120) {
        return ERROR_CHECK_DATA_IN_LIST;
    }

    return SUCCESS;
}

//
int F_check_list(List * list) {
    list->check_data = 5 * (list->data) + 120;
    list->checksum = (182 * ((long) list->tail) + 17 * ((long) list->head) + 291) % 1274;
}

//
int Ok_node(Node * node) {
    if (node == NULL) {
        return ERROR_PTR;
    }
    if (node->canary1 != CANARY || node->canary2 != CANARY) {
        return ERROR_CANARY;
    }
    if (node->checksum != (182 * (long) (node->next) + 17 * (long) (node->prev) + 291) % 1274) {
        return ERROR_CHECKSUM;
    }
    return SUCCESS;
}

//
int print_node (long  node_id , long list_id ){
    Node * node = Decoding_node(node_id);
    List * list = Decoding_list(list_id);
    if (!list ){
        return BAD_LIST_ID;
    }
    if ( list -> data == 0){
        return NO_ELEMENT_IN_LIST;
    }
    if (!node ){
        return BAD_NODE_ID;
    }
    /*if ( node -> next == NULL && list -> data == 1){
        return BAD_ELEM_FOR_PRINT;
    }*/
    if ( node -> next == NULL ){
        return BAD_ELEM_FOR_PRINT;
    }
    else{
        while (node  != NULL){
            printf("node  = %d \n" , node -> data  ); // печатать все
            node = node -> next ;
        }
    }
    return SUCCESS;
}

//
long Encoding_node (Node * node ){
    long node_id =(((long ) node) + 121 )*997;
    return node_id;
}

//
long Encoding_list (List * list ){
    long list_id = (((long ) list) + 121)*997 ;
    return list_id;
}

//
Node * Decoding_node (long node_id ){
    if (node_id% 997 != 0 || node_id == 0){
        return NULL;
    }
    Node * node = (Node *) (node_id/997 - 121);
    return node;
}

//
List * Decoding_list (long list_id ){
    if (list_id% 997 != 0 || list_id == 0){
        return NULL;
    }
    List * list = (List *) (list_id/997 - 121);
    return list;
}

//
int Check_elem_in_list (Node * node , List * list ){
    if (node->next != NULL && node -> prev != NULL ){
        if (node -> next-> prev == node && node -> prev-> next == node){
            return ELEM_IN_LIST;
        }
    }
    if (node->next == NULL && node -> prev != NULL ){
        if ( node -> prev-> next == node){
            return ELEM_IN_LIST;
        }
    }
    if (node->next != NULL && node -> prev == NULL ){
        if ( node -> next-> prev == node){
            return ELEM_IN_LIST;
        }
    }
    if (node->next == NULL && node -> prev == NULL  && (list -> head == node || list -> tail == node ) ){
        return ELEM_IN_LIST;
    }
    return SUCCESS;
}

//
int Check_elem_out_list (Node * node , List * list ) {
    if (node->next != NULL && node -> prev != NULL ){
        if (node -> next-> prev == node && node -> prev-> next == node){
            return SUCCESS;
        }
    }
    if (node->next == NULL && node -> prev != NULL ){
        if ( node -> prev-> next == node){
            return SUCCESS;
        }
    }
    if (node->next != NULL && node -> prev == NULL ){
        if ( node -> next-> prev == node){
            return SUCCESS;
        }
    }
    if (node->next == NULL && node -> prev == NULL  && (list -> head == node || list -> tail == node )){
        return SUCCESS;
    }
    return ELEM_OUT_LIST;

}

//
void print_mistake (int cod_mistake ){
    switch (cod_mistake)
    {
        case ERROR_PTR                : printf ("Null ptr\n");break;
        case ERROR_CANARY             : printf ("Node changed(Canary)\n");break;
        case ERROR_CHECKSUM           : printf ("Checksum changed\n");break;
        case ELEM_OUT_LIST            : printf ("Elem out list . You can not (delete/or Insert after) this node\n");break;
        case ELEM_IN_LIST             : printf ("Elem in list . You can not push this node\n");break;
        case NO_ELEMENT_IN_LIST       : printf ("You can not print , because the list is empty\n");break;
        case ERROR_PTR_IN_LIST        : printf ("List with null ptr \n");break;
        case ERROR_CANARY_IN_LIST     : printf ("List changed (Canary) \n");break;
        case ERROR_CHECKSUM_IN_LIST   : printf ("Checksum changed in list \n");break;
        case ERROR_CHECK_DATA_IN_LIST : printf ("Number of elements changed\n");break;
        case BAD_ELEM_FOR_PRINT       : printf ("This node does not have the following. You can't print starting this node\n");break;
        case BAD_NODE_ID              : printf ("This id is not in the list\n");break;
        case BAD_LIST_ID              : printf ("Bad ID list\n");break;
    }
}

//
int Insert_after (long node_id , long node_id_new , long list_id){
    Node * node = Decoding_node(node_id);
    if (!node ){
        return BAD_NODE_ID;
    }
    List * list = Decoding_list(list_id);
    if (!list ){
        return BAD_LIST_ID;
    }
    Node * node_new = Decoding_node(node_id_new);
    if (!node_new ){
        return BAD_NODE_ID;
    }
    OK(Check_elem_in_list( node_new , list )); // случай отсутствия элементов рассмотрен тут !
    OK(Check_elem_out_list( node , list));
    OK(Ok_list(list));
    OK(Ok_node(node));
    OK(Ok_node(node_new));
    if ( node -> next == NULL ) {
        OK(push_back( list_id , node_id_new ));
    }
    else {
        node_new -> prev = node ;
        node -> next -> prev = node_new ;
        node_new -> next = node -> next ;
        node -> next = node_new ;
        list->data = (list->data) + 1;
        F_checksum_node(node);
        F_checksum_node(node_new);
        F_checksum_node(node_new -> next);
        F_check_list(list);
        OK(Ok_list(list));
        OK(Ok_node(node));
        OK(Ok_node(node_new));
    }
    return SUCCESS;
}

//
int Delete (long node_id , long list_id){
    Node * node = Decoding_node(node_id);
    if (!node ){
        return BAD_NODE_ID;
    }

    List * list = Decoding_list(list_id);
    if (!list ){
        return BAD_LIST_ID;
    }

    OK(Check_elem_out_list( node , list));
    OK(Ok_list(list));
    OK(Ok_node(node));
    if (node -> prev == NULL){
        OK(pop_front(list_id));
    }
    else if (node -> next == NULL ){
        OK(pop_back(list_id));
    }
    else {
        node -> next -> prev = node -> prev ;
        node -> prev -> next = node -> next ;
        list->data = (list->data) - 1;
        F_checksum_node(node -> next);
        F_checksum_node(node -> prev);
        F_check_list(list);
        OK(Ok_list(list));
        OK(Ok_node(node -> next));
        OK(Ok_node(node -> prev));
        node -> next = NULL ;
        node -> prev = NULL ;
        free (node);
    }
    return SUCCESS;
}

//
int Delete_all (long list_id ){
    List * list = Decoding_list(list_id);
    OK(Ok_list (list));
    //
    while (list->head->next != NULL){
        pop_front(list_id);
    }
    list -> data = 0;
    return SUCCESS;
}