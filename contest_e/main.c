#include <stdio.h>
#include <stdlib.h>
#include <math.h>
////////////
#define N 1000
////////////
typedef int type;
////////////
struct Stack {
    int n;
    int size;
    type * ptr;
};
/////////////
struct Stack * stack_create(int size) {
    struct Stack * stack;
    stack = calloc(1, sizeof(struct Stack));
    stack -> size = size;
    stack -> n = 0;
    stack ->ptr = malloc(sizeof(type) * stack->size);
    return stack;
}
void stack_push(struct Stack * stack, type x) {
    if (stack -> n >= stack -> size) {
        stack -> size += 10;
        stack -> ptr = realloc(stack -> ptr, sizeof(type) * stack->size);
    }
    stack -> ptr[stack -> n] = x;
    (stack->n)++;
}

type stack_pop(struct Stack * stack) {
    type res;
    (stack->n) --;
    res = stack -> ptr[stack -> n];
    //(s->n) --;
    return res;
}
type stack_get(struct Stack * s) {
    type res;
    res = s -> ptr[s -> n - 1];
    return res;
}
int stack_is_empty(struct Stack * stack) {
    if ((stack -> n) == 0)
        return 1;
    return 0;
}
void stack_print(struct Stack * stack) {
    int i;
    for (i = 0; i < stack -> n; i++) {
        printf("%d ", stack -> ptr[i]);
    }
    if ((stack -> n) == 0) {
        printf("Empty stack");
    }
    printf("\n");
}
int  stack_size(struct Stack * stack) {
    int k;
    k = (stack -> n);
    return k;
}
void stack_clear(struct Stack * stack) {
    stack -> n = 0;
}

void stack_destroy(struct Stack * stack) {
    free(stack->ptr);
    free(stack);
}


int main () {
    int i = 0;
    char t = 0;
    char d = 0;
    struct Stack * sp = stack_create(10);
    char a[N];
    for (i = 0; i < N; i++) {
        scanf("%c", &a[i]);
        if (a[i] == '\n') {
            break;
        }
        if (a[i] == 43) {
            stack_push(sp, ((stack_pop(sp)) + (stack_pop(sp))));
        }
        else if (a[i] == 45) {
            t = stack_pop(sp);
            d = stack_pop(sp);
            if (t > d) {
                stack_push(sp, d - t);
            }
            else stack_push(sp, d - t);
        }
        else if (a[i] == 42) {
            stack_push(sp, ((stack_pop(sp)) * (stack_pop(sp))));
        }
        else if (a[i] == '=') {
            stack_print(sp);
            break;
        }
        else if (a[i] == 32) {
            continue;
        }
        else {
            stack_push(sp, a[i] - '0');
        }
    }
    stack_destroy(sp);
    return 0;
}