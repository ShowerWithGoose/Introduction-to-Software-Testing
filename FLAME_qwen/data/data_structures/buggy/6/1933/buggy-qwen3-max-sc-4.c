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
    while ((scanf_s("%d",&op))!=EOF&&op!=-1) { // @@ [Using scanf_s instead of scanf causes compilation error on non-Windows platforms or without proper compiler support. The reference program uses standard scanf, and the problem expects portable code.]
        if (op == 1) {
            scanf_s("%d",&data); // @@ [Same issue: scanf_s is not standard C and may not be available, leading to compilation failure.]
            //可堆栈
            if (data == -1)
                break; // @@ [This check is incorrect: the problem states that -1 only terminates the entire operation sequence when it appears as an operation code, not as a pushed value. Pushing -1 should be allowed if preceded by 1. This logic breaks the specification and may cause premature termination.]
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