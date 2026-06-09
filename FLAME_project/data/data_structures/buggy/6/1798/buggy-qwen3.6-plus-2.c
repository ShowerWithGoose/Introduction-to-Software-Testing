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
    while (~scanf("%d", &n)) { @@ The loop condition `~scanf(...)` is incorrect for stopping at -1. `scanf` returns the number of items successfully read. If it reads -1, it returns 1. `~1` is -2 (true). The loop should continue until n is -1, but the logic inside uses `else break` which is attached to the `if (n == 0)` block incorrectly. More importantly, the problem states -1 ends operations. The current structure `if (n==1) ... if (n==0) ... else break` means if n is not 0 (and not 1, since the first if handles 1), it breaks. So if n is -1, it enters the first if (false), then the second if (false), then the else branch executes `break`. This part actually works for termination. However, the critical error is that `sta` is not initialized. `sta.top` contains garbage value.
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
                printf("%d", sta.data [sta.top - 1]);
                sta.top--;
            }
        } else
            break;
    }
    return 0;
}