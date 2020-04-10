#include <stdio.h>
#include <stdlib.h>
//
#define ERROR_PTR -1
#define LAST_NODE -2
#define BAD_ELEM -3
#define ERROR_CANARY -4
#define ERROR_CHECKSUM -5
#define GOOD_FUNCTION 0
#define CANARY 230
//
typedef int type_t;
//
Node * CreateNode ( type_t data) ;
Node * Node_FindNext(Node* begin_elem, int elem) ;
int    delete (Node * node_delete , Node * List) ;
int    insert (node * this_ , node * new_node , node * list , type_t elem) ;
int    Ok ( Node * node ) ;
//int    OkForUser (Node * node) ;
int    F_checksum (Node * node) ;
int    insert(node* this_, type_t elem) ;
//int    delete (Node * node_delete) ;
int    push_front ( Node * new_node , Node * list ) ;
int    pop_front ( Node * delete_node , Node * list ) ;
int    pop_back () ;#include <stdio.h>
#include <stdlib.h>
//
#define ERROR_PTR -1
#define LAST_NODE -2
#define BAD_ELEM -3
#define ERROR_CANARY -4
#define ERROR_CHECKSUM -5
#define GOOD_FUNCTION 0
#define CANARY 230
//
typedef int type_t;
//
Node * CreateNode ( type_t data) ;
Node * Node_FindNext(Node* begin_elem, int elem) ;
int    delete (Node * node_delete , Node * List) ;
int    insert (node * this_ , node * new_node , node * list , type_t elem) ;
int    Ok ( Node * node ) ;
//int    OkForUser (Node * node) ;
int    F_checksum (Node * node) ;
int    insert(node* this_, type_t elem) ;
//int    delete (Node * node_delete) ;
int    push_front ( Node * new_node , Node * list ) ;
int    pop_front ( Node * delete_node , Node * list ) ;
int    pop_back () ;
int    push_back () ;

//

typedef struct
{
    int     canary1 ;
    type_t  data ;
    Node *  next ;
    Node *  prev ;
    int     checksum ;
    int     canary2 ;
} Node;
//
int main ()
{
    Node * list = CreateNode(0);

}
//
Node* Node_FindNext(Node* begin_elem, int elem)
{
    while (begin_elem != NULL)
    {
        if (begin_elem -> data == value_to_find) ;
        return begin_elem ;
        begin_elem = begin_elem -> next ;
    }
    return NULL;
}
//
int push_front ( Node * new_node , Node * list )
{
    Ok ( new_node ) ;
    Ok ( list ) ;
    //......................//
    new_node -> next = list -> prev ;
    list -> prev = new_node ;
    new_node -> prev = NULL ;
    list -> data = list -> data + 1;
    F_checksum (Node * new_node) ;
    F_checksum (Node * list) ;
    //.......................//
    Ok ( new_node ) ;
    Ok ( list ) ;
}
//
int pop_front ( Node * delete_node , Node * list )
{
    Ok (delete_node) ;
    Ok (list) ;
    if ((delete_node -> next)-> prev != delete_node || (delete_node -> prev)-> next != delete_node) // элемент не в списке
    {
        return BAD_ELEM ;
    }
    //................//
    list -> prev = delete_node -> next ;
    (delete_node -> next ) -> prev = NULL ;
    delete_node = NULL ;
    F_checksum(list) ;
    //......................//
    Ok (list) ;
}
//
int pop_back ()
{

}
//
int push_back ()
{

}
//
#define returnIfNotOK(node) / /////////////////////////  стоит так делать ?
{/
ok(node)


}/


int delete (Node * node_delete , Node * List)
{
    Ok (node_delete) ;

    Ok (list) ;


    if ((node_delete -> next)-> prev != node_delete || (node_delete -> prev)-> next != node_delete) // элемент не в списке
    {
        return BAD_ELEM ;
    }
    //......................//
    ( node_delete -> prev ) -> next = node -> next ;
    ( node_delete -> next ) -> prev = node -> prev ;
    F_checksum (Node * List) ;
    node_delete == NULL ;
    list -> data = list -> data - 1;
    //......................//
    Ok (list) ;
    return GOOD_FUNCTION ;
}
//

int insert (node * this_ , node * new_node , node * list)
{
    Ok (this_) ;
    Ok (new_node) ;
    Ok (list) ;
    //......................//
    if (!(this_ -> next ))
    {
        printf ("LAST_NODE\n");
        return LAST_NODE;
    }
    //new_node = (Node *) calloc (1 , sizeof(Node) ) ;
    //
    new_node -> prev = this_ ;
    ( this_ -> next ) -> prev = new_node ;
    new_node -> next = this_ -> next ;
    this_ -> next = new_node ;
    list -> data = list -> data + 1;
    F_checksum (Node * node) ;
    F_checksum (Node * list) ;
    F_checksum (Node * this_) ;
    //.......................//
    Ok (this_) ;
    Ok (new_node) ;
    Ok (list) ;
    return GOOD_FUNCTION ;
}
//
Node * CreateNode ( type_t data)
{
    Node * node = (Node *) calloc ( 1 , sizeof(Node) ) ;
    if NULL ////////////////////////////////дописать
        node -> canary1 = CANARY ;
    node -> data = data ;
    node -> next = node -> prev = NULL ;
    F_checksum (Node * node);
    node -> canary2 = CANARY ;
    return node;

}

int Ok ( Node * node )
{
    if ( node == NULL)
    {
        printf ("ERROR_PTR\n");
        return ERROR_PTR ;
    }
    if ( node -> canary1 != node -> canary2 != CANARY )
    {
        printf ("ERROR_CANARY \n");
        return ERROR_CANARY;
    }

    if ( node -> checksum != (182 * (node -> next) + 17 * (node -> prev) + 291) % 1274 )
    {
        printf ("ERROR_CHECKSUM\n");
        return ERROR_CHECKSUM;
    }
    return GOOD_FUNCTION ;
}
//
int F_checksum (Node * node)
{
    node -> checksum = (182*(node -> next) + 17*(node -> prev) + 291) % 1274  ;
}
/*int OkForUser (Node * node)
{
    switch (Ok (node))
    {
        case ERROR_PTR   : printf ("ERROR_PTR\n");break;
        case ERROR_CANARY   : printf ("ERROR_CANARY \n");break;
        case ERROR_CHECKSUM : printf ("ERROR_CHECKSUM\n");break;
        case GOOD_FUNCTION     : printf ("GOOD_FUNCTION\n");break;
    }
}*/



int    push_back () ;

//

typedef struct
{
    int     canary1 ;
    type_t  data ;
    Node *  next ;
    Node *  prev ;
    int     checksum ;
    int     canary2 ;
} Node;
//
int main ()
{
    Node * list = CreateNode(0);

}
//
Node* Node_FindNext(Node* begin_elem, int elem)
{
    while (begin_elem != NULL)
    {
        if (begin_elem -> data == value_to_find) ;
        return begin_elem ;
        begin_elem = begin_elem -> next ;
    }
    return NULL;
}
//
int push_front ( Node * new_node , Node * list )
{
    Ok ( new_node ) ;
    Ok ( list ) ;
    //......................//
    new_node -> next = list -> prev ;
    list -> prev = new_node ;
    new_node -> prev = NULL ;
    list -> data = list -> data + 1;
    F_checksum (Node * new_node) ;
    F_checksum (Node * list) ;
    //.......................//
    Ok ( new_node ) ;
    Ok ( list ) ;
}
//
int pop_front ( Node * delete_node , Node * list )
{
    Ok (delete_node) ;
    Ok (list) ;
    if ((delete_node -> next)-> prev != delete_node || (delete_node -> prev)-> next != delete_node) // элемент не в списке
    {
        return BAD_ELEM ;
    }
    //................//
    list -> prev = delete_node -> next ;
    (delete_node -> next ) -> prev = NULL ;
    delete_node = NULL ;
    F_checksum(list) ;
    //......................//
    Ok (list) ;
}
//
int pop_back ()
{

}
//
int push_back ()
{

}
//
#define returnIfNotOK(node) / /////////////////////////  стоит так делать ?
{/
ok(node)


}/


int delete (Node * node_delete , Node * List)
{
    Ok (node_delete) ;

    Ok (list) ;


    if ((node_delete -> next)-> prev != node_delete || (node_delete -> prev)-> next != node_delete) // элемент не в списке
    {
        return BAD_ELEM ;
    }
    //......................//
    ( node_delete -> prev ) -> next = node -> next ;
    ( node_delete -> next ) -> prev = node -> prev ;
    F_checksum (Node * List) ;
    node_delete == NULL ;
    list -> data = list -> data - 1;
    //......................//
    Ok (list) ;
    return GOOD_FUNCTION ;
}
//

int insert (node * this_ , node * new_node , node * list)
{
    Ok (this_) ;
    Ok (new_node) ;
    Ok (list) ;
    //......................//
    if (!(this_ -> next ))
    {
        printf ("LAST_NODE\n");
        return LAST_NODE;
    }
    //new_node = (Node *) calloc (1 , sizeof(Node) ) ;
    //
    new_node -> prev = this_ ;
    ( this_ -> next ) -> prev = new_node ;
    new_node -> next = this_ -> next ;
    this_ -> next = new_node ;
    list -> data = list -> data + 1;
    F_checksum (Node * node) ;
    F_checksum (Node * list) ;
    F_checksum (Node * this_) ;
    //.......................//
    Ok (this_) ;
    Ok (new_node) ;
    Ok (list) ;
    return GOOD_FUNCTION ;
}
//
Node * CreateNode ( type_t data)
{
    Node * node = (Node *) calloc ( 1 , sizeof(Node) ) ;
    if NULL ////////////////////////////////дописать
        node -> canary1 = CANARY ;
    node -> data = data ;
    node -> next = node -> prev = NULL ;
    F_checksum (Node * node);
    node -> canary2 = CANARY ;
    return node;

}

int Ok ( Node * node )
{
    if ( node == NULL)
    {
        printf ("ERROR_PTR\n");
        return ERROR_PTR ;
    }
    if ( node -> canary1 != node -> canary2 != CANARY )
    {
        printf ("ERROR_CANARY \n");
        return ERROR_CANARY;
    }

    if ( node -> checksum != (182 * (node -> next) + 17 * (node -> prev) + 291) % 1274 )
    {
        printf ("ERROR_CHECKSUM\n");
        return ERROR_CHECKSUM;
    }
    return GOOD_FUNCTION ;
}
//
int F_checksum (Node * node)
{
    node -> checksum = (182*(node -> next) + 17*(node -> prev) + 291) % 1274  ;
}
/*int OkForUser (Node * node)
{
    switch (Ok (node))
    {
        case ERROR_PTR   : printf ("ERROR_PTR\n");break;
        case ERROR_CANARY   : printf ("ERROR_CANARY \n");break;
        case ERROR_CHECKSUM : printf ("ERROR_CHECKSUM\n");break;
        case GOOD_FUNCTION     : printf ("GOOD_FUNCTION\n");break;
    }
}*/


