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
        if (n == 0) { // @@ This should be "else if (n == 0)" to avoid breaking the loop after processing a push operation. As written, when n == 1, the second if evaluates false and the else branch (line 42) executes, breaking the loop prematurely.
            if (sta.top == 0)
                printf("error ");
            else {
                printf("%d", sta.data [sta.top - 1]); // @@ Missing space after %d. According to the problem, each popped element should be followed by a space. Should be "%d ".
                sta.top--;
            }
        } else
            break;
    }
    return 0;
}