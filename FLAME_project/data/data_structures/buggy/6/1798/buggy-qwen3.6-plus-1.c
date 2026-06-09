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
    while (~scanf("%d", &n)) { // @@ The loop condition `~scanf(...)` continues on EOF or error, but the problem specifies `-1` as the terminator. More critically, the logic inside uses `if (n == 0) ... else break`, which breaks the loop for ANY input that is not 1 or 0 (including -1, but also potentially other inputs if not handled correctly). However, the main issue causing Runtime Error or incorrect behavior here is likely uninitialized memory or logic flow. Let's look closer. The `sta` variable is declared but `init` is never called, so `sta.top` is uninitialized. Accessing uninitialized memory leads to undefined behavior/Runtime Error.
        if (n == 1) {
            if (sta.top == MAX_SIZE)
                printf("error ");
            else {
                scanf("%d", &m);
                sta.data[sta.top ] = m;
                sta.top++;
            }
        }
        if (n == 0) { // @@ This should be `else if (n == 0)` to avoid checking this block when `n == 1`. If `n==1`, we push. Then we check `if (n==0)`, which is false, so we go to `else break`. This means after every push operation, the loop breaks! This is a logical error causing premature termination.
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