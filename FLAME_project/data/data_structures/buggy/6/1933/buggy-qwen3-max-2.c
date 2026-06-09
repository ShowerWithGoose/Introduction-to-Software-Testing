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
    while ((scanf_s("%d",&op))!=EOF&&op!=-1) { // @@ [The function 'scanf_s' is not available in standard C (it's a Microsoft-specific secure version). The correct function to use is 'scanf', which matches the standard library included via <stdio.h>. Using 'scanf_s' causes a compilation error on non-Microsoft compilers due to implicit declaration and undefined reference.]
        if (op == 1) {
            scanf_s("%d",&data); // @@ [Same issue: 'scanf_s' is not standard C; should use 'scanf' for portability and correctness with <stdio.h>.]
            //可堆栈
            if (data == -1)
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