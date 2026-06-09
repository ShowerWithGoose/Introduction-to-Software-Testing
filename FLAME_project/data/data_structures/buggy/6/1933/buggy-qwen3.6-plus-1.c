#include <stdio.h> // @@ The function scanf_s is not standard in GCC/Linux environments; it should be replaced with scanf to avoid compilation/linking errors.
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
    while ((scanf("%d",&op))!=EOF&&op!=-1) { // @@ Changed scanf_s to scanf to fix the undefined reference error during linking.
        if (op == 1) {
            scanf("%d",&data); // @@ Changed scanf_s to scanf to fix the undefined reference error during linking.
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