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
    while ((scanf_s("%d",&op))!=EOF&&op!=-1) { // @@ [Error: scanf_s is not standard C; should use scanf instead. Also, the condition should check for -1 after reading, but the loop structure is incorrect for the problem's input format.]
        if (op == 1) {
            scanf_s("%d",&data); // @@ [Error: scanf_s is not standard C; should use scanf instead.]
            //可堆栈
            if (data == -1) // @@ [Error: This condition incorrectly treats a pushed value of -1 as end-of-operations, but -1 is only the operation code for termination, not a pushed value.]
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