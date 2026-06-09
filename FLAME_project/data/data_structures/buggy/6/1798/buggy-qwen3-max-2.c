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
    stack->data[++stack->top] = value; // @@ [This increments top before assigning, causing the first element to be stored at index 1 instead of 0, and potentially writing beyond the array if top reaches MAX_SIZE]
}

int pop(stack *stack) {
    return stack->data[stack->top--]; // @@ [This accesses data[top] before decrementing, but since push uses pre-increment, pop may read from an uninitialized or incorrect location; also, no bounds check here]
}

int main() {
    int n, m;
    stack sta;
    while (~scanf("%d", &n)) { // @@ [The stack 'sta' is not initialized, so sta.top contains garbage value, leading to undefined behavior]
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
                printf("%d", sta.data [sta.top - 1]); // @@ [Missing space after %d in printf; expected output requires a space after each popped value]
                sta.top--;
            }
        } else
            break;
    }
    return 0;
}