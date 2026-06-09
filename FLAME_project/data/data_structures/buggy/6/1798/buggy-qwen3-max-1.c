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
    stack->data[++stack->top] = value; // @@ [Off-by-one error: increments top before assignment, causing data to be written at index 1 on first push and potentially writing beyond MAX_SIZE-1 when stack is full]
}

int pop(stack *stack) {
    return stack->data[stack->top--]; // @@ [Off-by-one error: accesses data[top] where top is already pointing past the last valid element due to pre-increment in push]
}

int main() {
    int n, m;
    stack sta;
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
        if (n == 0) { // @@ [Logic error: should be 'else if' to avoid checking pop condition after a push or when n is -1]
            if (sta.top == 0)
                printf("error ");
            else {
                printf("%d", sta.data [sta.top - 1]); // @@ [Missing space after %d in printf format string, causing output format mismatch]
                sta.top--;
            }
        } else
            break;
    }
    return 0;
}