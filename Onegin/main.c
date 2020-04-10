#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <assert.h>
//.....................//
#define NOT_A_LETTER -10
#define CLEAN_ARRAY -1
#define ERROR_ARRAY -230
#define CANNOT_OPEN_FILE -231
#define GOOD_FUNCTION 0
//.....................//
typedef struct
{
    char * text_ptr ;
    int string_length;
} text_struct;
//.....................//
int              r_file_w_array (char * data_file ,char ** text , int * chr); // read file and writes to an array of structures || возвращает количество элементов
int              create_array_data(int * chr , int * nstr ,char ** text ); // функця создаёт массив и записывает туда данные из файла
int              compare_top (const void* ptr1, const void* ptr2);
int              cmt (const void* string1,const void* string2);
int              compare_botton (const void* ptr1, const void* ptr2);
int              cod (char * letter_ptr );
int              create_array_struct (int * nstr ,int * chr , char ** text , text_struct ** array_struct );// функция создаёт масисив структур
//.....................//
int main ()
{
    printf("%d \n", '\r');
    setlocale(LC_ALL,"Russian");
    int i = 0;
    char * text = NULL ;
    int chr = 0;
    int nstr = 0;
    text_struct * array_struct = NULL;
    r_file_w_array( "Onegin", &text , &chr);
    create_array_data ( &chr , &nstr , &text);
    create_array_struct ( &nstr , &chr , &text, &array_struct);
    /*for ( int i = 0 ; i < nstr ; i++)
    {
        printf("%s \n", ((array_struct+i)->text_ptr ) );
    }*/
    //printf("%d \n", i );
    //printf("%s \n", ((array_struct+1)->text_ptr ));
    qsort (array_struct,nstr,sizeof(text_struct), compare_botton);
    //qsort (array_struct,nstr,sizeof(text_struct), cmt);
    for ( int i = 0 ; i < nstr ; i++)
    {
        printf("\n %s \n", ((array_struct+i)->text_ptr ) );
    }
    /*qsort (array_struct,nstr,sizeof(text_struct), cmt);
    for ( int i = 0 ; i < nstr ; i++)
    {
        printf("\n %s \n", ((array_struct+i)->text_ptr ) );
    }*/
    free(text);
    return GOOD_FUNCTION;
}

int r_file_w_array (char * data_file , char ** text , int * chr )
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
    return GOOD_FUNCTION ;

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
    return GOOD_FUNCTION;
}
int  create_array_struct (int * nstr ,int * chr , char ** text , text_struct ** array_struct)
{
    *array_struct = (text_struct *) calloc (*nstr+1,sizeof(text_struct));
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
    return GOOD_FUNCTION;
}
//....................................................//
int compare_top (const void* ptr1, const void* ptr2)
{
    int i = 0; // курсор первой строчки
    int k = 0; // курсор второй строчки
    int len = 0; // счетчик проверки равенства строк
    int c_string1 = 0;
    int c_string2 = 0;
    char * string1 = (*((const text_struct*) ptr1)).text_ptr;// адрес первой строчки
    char * string2 = ((const text_struct*) ptr2)->text_ptr;// адрес второй строчки
    int length1 = ((const text_struct*) ptr1)->string_length; // длина первой строчки
    int length2 = ((const text_struct*) ptr2)->string_length; // длина второй строчки
    while ( *(string1+i ) != '\0' || *(string2+k ) != '\0' )
    {
        c_string1 = cod ( string1+i  );
        c_string2 = cod ( string2+k  );
        if ( c_string1 != NOT_A_LETTER && c_string2 != NOT_A_LETTER )
        {
            if (c_string1>c_string2)
                return 1;
            if (c_string1<c_string2)
                return -1;
        }
        if (c_string1 == c_string2)
        {
            len++;
            i++;
            k++;
        }
        if ( c_string1 != NOT_A_LETTER && c_string2 == NOT_A_LETTER )
            k++;
        if ( c_string1 == NOT_A_LETTER && c_string2 != NOT_A_LETTER )
            i++;
    }
    if (len == length1 || len == length2)
        return 0 ;
}
//..............................................//
int cmt (const void* string1, const void* string2)
{
    return strcmp(*((char**) string1), *((char**) string2));
}
int compare_botton (const void* ptr1, const void* ptr2)
{
    int i = 1; // курсор первой строчки
    int k = 1; // курсор второй строчки
    int len = 0; // счетчик проверки равенства строк
    int c_string1 = 0;
    int c_string2 = 0;
    char * string1 = (*((const text_struct*) ptr1)).text_ptr;// адрес первой строчки
    char * string2 = ((const text_struct*) ptr2)->text_ptr;// адрес второй строчки
    int length1 = ((const text_struct*) ptr1)->string_length; // длина первой строчки
    int length2 = ((const text_struct*) ptr2)->string_length; // длина второй строчки
    while ( i < length1 || k < length2 )
    {
        c_string1 = cod ( string1+length1-i  );
        c_string2 = cod ( string2+length2-k  );
        if ( c_string1 != NOT_A_LETTER && c_string2 != NOT_A_LETTER )
        {
            if (c_string1>c_string2)
                return 1;
            if (c_string1<c_string2)
                return -1;
        }
        if (c_string1 == c_string2)
        {
            len++;
            i++;
            k++;
        }
        if ( c_string1 != NOT_A_LETTER && c_string2 == NOT_A_LETTER )
            k++;
        if ( c_string1 == NOT_A_LETTER && c_string2 != NOT_A_LETTER )
            i++;
    }
    if (len = length1)
        return 0;
}
int cod (char * letter_ptr )
{
    static int count = 0;
    static char * alph = NULL ;
    static int chr = 0;
    int i = 0 ;
    int c_letter_ptr = 0;
    if (count == 0)
    {
        r_file_w_array ("alphabet.txt" , &alph , &chr);
    }
    if (!letter_ptr && count == 0)
    {
        return 1;
    }
    if (!letter_ptr)
    {
        free(alph);
        return CLEAN_ARRAY ;
    }
    count++;
    while (*letter_ptr != alph[i])
    {
        i++;
        if( i > chr)
        {
            i = 230;
            break;
        }
    }
    c_letter_ptr = i;
    return c_letter_ptr;
}