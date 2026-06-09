#include <stdio.h>
#define MAX_SIZE 100
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;
void initializeStack(Stack *stack) {
    stack->top = -1;
}
int isEmpty(Stack *stack) {
    return stack->top == -1;
}
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}
void push(Stack *stack, int value) {
    if (!isFull(stack)) {
        stack->items[++stack->top] = value;
    } else {
        printf("error ");
    }
}
int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    } else {
        printf("error ");
        return -1;
    }
}
int main() {
    Stack stack;
    initializeStack(&stack);
    int operation;
    while (scanf("%d", &operation) == 1 && operation != -1) {
        if (operation == 1) {
            int value;
            scanf("%d", &value);
            push(&stack, value);
        } else if (operation == 0) {
            int popped = pop(&stack);
            if (popped != -1) {
                printf("%d ", popped);
            }
        }
    }
    return 0;
}

