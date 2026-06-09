#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} stack;

void init(stack *stack) {
    stack->top = 0;
}

void push(stack *stack, int value) {
    stack->data[++stack->top] = value;
}

int pop(stack *stack) {
    return stack->data[stack->top--];
}

int main() {
    int n, m;
    stack sta; // @@ Stack not initialized; top contains garbage value. Must call init(&sta) before use.
    while (~scanf("%d", &n)) {
        if (n == 1) {
            if (sta.top == MAX_SIZE)
                printf("error ");
            else {
                scanf("%d", &m);
                sta.data[sta.top ] = m;
                sta.top++;
            }
        }
        if (n == 0) {
            if (sta.top == 0)
                printf("error ");
            else {
                printf("%d", sta.data [sta.top - 1]); // @@ Missing space after the popped element. Should be printf("%d ", ...);
                sta.top--;
            }
        } else // @@ The else belongs to the second if, causing the loop to break immediately when n==1 (since the second if is false). Use else if for n==0 and a separate else for -1.
            break;
    }
    return 0;
}