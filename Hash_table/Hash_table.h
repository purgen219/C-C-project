#ifndef TheHead

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//.......................//
using namespace std;
//.......................//
#define STATIC_SIZE 200
#define SUCCESS 0
#define CANNOT_OPEN_FILE -1
#define BAD_NODE -2
#define ELEM_NOT_IN_LIST 1
#define ELEM_IN_LIST 2
#define SUCCESS1 3
#define SUCCESS2 4
#define SUCCESS3 5
#define SUCCESS4 6
#define NO_ELEMENT_IN_LIST -3

//.......................//
typedef struct info_string_ {
    char * text_ptr;
    int string_length;
    info_string_():
        text_ptr(nullptr),
        string_length(0)
    {}
    ~info_string_()
    {}
}info_string;
//.......................//
int r_file_w_array (const char * data_file , char ** text , int * chr )
{
    FILE* file=fopen(data_file, "r");
    if (!file)
    {
        printf("Cannot open %s\n" , data_file);
        return CANNOT_OPEN_FILE;
    }
    fseek(file,0,SEEK_END);
    *chr = ftell(file);
    fseek( file , 0 , SEEK_SET );
    *text = (char *) calloc(*chr +1,sizeof(char));
    *chr = fread (*text , sizeof(char) , *chr , file);
    //printf("%d !!!!!!" , *chr);
    fclose(file);
    return SUCCESS ;

}
int create_array_data(int * chr , int * nstr ,char ** text )
{
    *(*text + *chr) = '\n';
    for(int i = 0 ; i < *chr+1 ; i++)
    {
        //printf(" |%c| = %d   %d \n" , *(*text + i) , *(*text + i) , i);
        if (*(*text + i)=='\n')
        {
            *nstr = *nstr + 1;
            *(*text + i)='\0';
            while ( *(*text + i+1) == '\n' || *(*text + i+1) == ' ' || *(*text + i+1) == '\t' )
            {
                i++;
            }
        }
    }
    //printf("\n/количество символов %d\n/количество строк %d \n",*chr, *nstr);
    return SUCCESS;
}
int  create_array_struct (int * nstr ,int * chr , char ** text , info_string ** array_struct)
{
    *array_struct = (info_string *) calloc (*nstr+1,sizeof(info_string));
    (*array_struct)->text_ptr = *text;
    (*array_struct)->string_length = strlen(*text);
    int k = 1;
    for (int i = 0 ; i < *chr ; i ++ )
    {
        if ( *(*text + i) == '\0')
        {
            while ( *(*text + i+1) == '\n' || *(*text + i+1) == ' ' || *(*text + i+1) == '\t' || *(*text + i+1) == '\0')
            {
                i++;
                if (i+1 >= *chr)
                {
                    break;
                }
            }
            if (i+1 >= *chr)
            {
                break;
            }
            (*array_struct+k)->text_ptr = (*text+i+1);
            (*array_struct+k)->string_length = strlen(*text+i+1);
            k++;
        }
    }
    //printf("%d !!!!!!",(*array_struct)->string_length);
    return SUCCESS;
}
int r_file_do_array_str(const char * data_file , info_string ** array_struct){
    char * text = nullptr;
    int chr = 0;
    int nstr = 0;
    r_file_w_array(data_file , &text , &chr );
    create_array_data( &chr , &nstr , &text );
    create_array_struct( &nstr , &chr , &text , array_struct);
    return nstr;
}
#endif
