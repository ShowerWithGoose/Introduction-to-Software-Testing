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
    stack sta; // @@ Local variable 'sta' is uninitialized, 'sta.top' contains garbage value. Should call init(&sta) or set sta.top = 0.
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
        if (n == 0) { // @@ Should be 'else if (n == 0)', otherwise the loop breaks immediately after processing a push operation (n == 1).
            if (sta.top == 0)
                printf("error ");
            else {
                printf("%d", sta.data [sta.top - 1]); // @@ Missing trailing space in format string, violates the output format requirement.
                sta.top--;
            }
        } else
            break;
    }
    return 0;
}