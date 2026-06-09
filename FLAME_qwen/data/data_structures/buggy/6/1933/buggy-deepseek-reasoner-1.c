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
    while ((scanf_s("%d",&op))!=EOF&&op!=-1) { // @@ Use of non-standard scanf_s; causes compilation error on compilers that do not support Microsoft extensions. Replace with scanf.
        if (op == 1) {
            scanf_s("%d",&data); // @@ Use of non-standard scanf_s; same issue. Replace with scanf.
            //可堆栈
            if (data == -1)
                break; // @@ Unnecessary and potentially incorrect: if push value is -1 (should not occur per problem), this breaks out of the entire loop, skipping remaining operations. According to the problem, push value is not -1, so this check is redundant and leads to behavior not specified.
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