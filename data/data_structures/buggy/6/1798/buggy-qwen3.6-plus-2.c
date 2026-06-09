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
    stack sta; // @@ Missing initialization: init(&sta); should be called here to set sta.top to 0, otherwise it contains a garbage value.
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
        if (n == 0) { // @@ Should be 'else if (n == 0)' to prevent the loop from breaking immediately after a push operation (n == 1) due to the subsequent 'else break;'.
            if (sta.top == 0)
                printf("error ");
            else {
                printf("%d", sta.data [sta.top - 1]); // @@ Missing space after %d. The output format requires a space after each popped element.
                sta.top--;
            }
        } else
            break;
    }
    return 0;
}