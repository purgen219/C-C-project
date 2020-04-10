#include <stdio.h>
#include <stdlib.h>
//
#define ERROR_PTR -1
#define LAST_NODE -2
#define BAD_ELEM -3
#define ERROR_CANARY -4
#define ERROR_CHECKSUM -5
#define BAD_ELEM_FOR_LIST -6
#define GOOD_FUNCTION 0
#define CANARY 230
#define CANARY_LIST 231
#define ERROR_CHECK_DATA -7
//
typedef int type_t;
//
typedef struct Node_t {
    int canary1;
    type_t data;
    struct Node_t *next;
    struct Node_t *prev;
    int checksum;
    int canary2;
} Node;
typedef struct List_t {
    int canary1;
    type_t data;
    struct Node_t *head;
    struct Node_t *tail;
    int check_data;
    int checksum;
    int canary2;
} List;

//
List *CreateList();

Node *CreateNode(type_t data);

int Ok_node(Node **node);

int Ok_list(List **list);

int F_checksum_node(Node **node);

int F_check_list(List **list);

int push_back(List **list, Node **node) ;

//
int main() {
    int res = 0;
    List *list = CreateList();
    Node *node_1 = CreateNode(0);
    Node *node_2 = CreateNode(1);
    Node *node_3 = CreateNode(2);
    push_back  ( &list , &(node_1) );
    printf(" %d\n %d\n %d\n %d\n", node_1->canary1, node_1->data, node_1->checksum, node_1->canary2);
    printf(" %d\n %d\n %d\n %d\n", list->canary1, list->data, list->checksum, list->canary2);
    return 0;
}

//
Node *CreateNode(type_t data) {
    Node *node = NULL;
    node = (Node *) calloc(1, sizeof(Node));
    node->canary1 = CANARY;
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    F_checksum_node(&node);
    node->canary2 = CANARY;
    return node;

}

List *CreateList() {
    static int count = 0;
    if (count == 0) {
        List *list = (List *) calloc(1, sizeof(List));
        list->canary1 = CANARY_LIST;
        list->data = 0;
        list->head = NULL;
        list->tail = NULL;
        list->canary2 = CANARY_LIST;
        F_check_list(&list);
        count++;
        return list;
    }

}
//
/*int pop_back (List ** list )
{
    Ok_list (list) ;
    //
    (*list) -> tail -> prev -> next = NULL ;
    (*list) -> tail = (*list) -> tail -> prev ;
    F_checksum (list) ;
    F_checksum (&((*list) -> tail)) ;
    //
    Ok_list (list) ;
    Ok_node (&((*list) -> tail)) ;
    return GOOD_FUNCTION ;
}*/
//
int push_back(List **list, Node **node) {

    Ok_node(node);
    Ok_list(list);
    if ((*list)->data == 0) {
        (*list)->head = (*node);
        (*list)->tail = (*node);
    }
    //
    ((*list)->tail)->next = *node;
    (*node)->next = NULL;
    (*node)->prev = (*list)->tail;
    (*list)->tail = (*node);
    (*list)->data = ((*list)->data) + 1;
    F_check_list(list);
    F_checksum_node(&((*node)->prev));
    F_checksum_node(node);
    //
    Ok_list(list);
    Ok_node(&((*node)->prev));
    Ok_node(node);
    return GOOD_FUNCTION;
}

//
int F_checksum_node(Node **node) {
    (*node)->checksum = (182 * ((unsigned int) (*node)->next) + 17 * ((int) ((*node)->prev)) + 291) % 1274;
}

int Ok_list(List **list) {
    if (list == NULL) {
        printf("ERROR_PTR_L\n");
        return ERROR_PTR;
    }
    if ((*list)->canary1 != CANARY || (*list)->canary2 != CANARY) {
        printf("ERROR_CANARY_L \n");
        return ERROR_CANARY;
    }
    if ((*list)->checksum != (182 * (int) ((*list)->tail) + 17 * (int) ((*list)->head) + 291) % 1274) {
        printf("ERROR_CHECKSUM_L\n");
        return ERROR_CHECKSUM;
    }
    if ((*list)->check_data != 5 * ((*list)->data) + 120) {
        printf("ERROR_CHECK_DATA_L\n");
        return ERROR_CHECK_DATA;
    }

    return GOOD_FUNCTION;
}

//
int F_check_list(List **list) {
    (*list)->check_data = 5 * ((*list)->data) + 120;
    (*list)->checksum = (182 * ((int) (*list)->tail) + 17 * ((int) (*list)->head) + 291) % 1274;
}

//
int Ok_node(Node **node) {
    if (node == NULL) {
        printf("ERROR_PTR\n");
        return ERROR_PTR;
    }
    if ((*node)->canary1 != CANARY || (*node)->canary2 != CANARY) {
        printf("ERROR_CANARY \n");
        return ERROR_CANARY;
    }
    if ((*node)->checksum != (182 * (int) ((*node)->next) + 17 * (int) ((*node)->prev) + 291) % 1274) {
        printf("ERROR_CHECKSUM\n");
        return ERROR_CHECKSUM;
    }
    return GOOD_FUNCTION;
}

//