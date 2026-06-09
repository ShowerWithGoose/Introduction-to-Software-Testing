#include <stdio.h>
#include <stdlib.h>
#define MAX_CAPACITY 100

struct DATA{
    int data[MAX_CAPACITY];
    int top;
};

void init(struct DATA* stack) {
    stack->top = -1;
}

int is_empty(struct DATA* stack) {
    return stack->top == -1;
}

int is_full(struct DATA* stack) {
    return stack->top == MAX_CAPACITY - 1;
}

int main() {
    struct DATA stack;
    init(&stack);
    int op;
    int data;
    while ((scanf_s("%d",&op))!=EOF&&op!=-1) { // @@ scanf_s is a non-standard Microsoft-specific function that causes compilation errors on standard GCC/Clang compilers. Use scanf instead.
        if (op == 1) {
            scanf_s("%d",&data); // @@ scanf_s is non-standard and will cause a compilation error on standard C compilers. Use scanf instead.
            //可堆栈
            if (data == -1) // @@ Logical error: The termination signal -1 is read into 'op', not 'data'. The problem also states pushed integers are not -1. This condition is incorrect.
                break;
            if (!is_full(&stack)) {
                stack.data[++stack.top] = data;
            }
            else
                printf("error ");
        }
        //出栈
        else if(op==0){
            //可删去元素
            if (!is_empty(&stack)) {
                printf("%d ", stack.data[stack.top]);
                stack.top--;
            }
            else
                printf("error ");
        }
    }
    return 0;
}