#include <stdio.h>
#include <stdlib.h>
//
#define N 100
#define BAD_ELEM -1
//
typedef struct _Decimal{
    unsigned char a[N];
    unsigned int n;
} Decimal;
//
int div3 (Decimal * number );
//
int main() {
    Decimal d = {{9, 9}, 1};  // число 123456789

    div3( &d);

    return 0;
}
//
int div3 (Decimal * number ){
    int res = 0 ;
    for (int i = 0 ; i <= (number->n) ; i++ ){
        if ( *(number->a+i) < 10 ){
            res = res + *(number->a+i);
        }
        if (*(number->a+i) >= 10 && *(number->a+i) < 100){
            res = res + *(number->a+i) % 10 + (res + *(number->a+i) - *(number->a+i) % 10) % 100;
        }
        if (*(number->a+i) >= 100){
            return BAD_ELEM;
        }
    }
    if (res % 3 == 0){
        printf("YES");
    }
    if (res % 3 != 0){
        printf("NO");
    }
}
