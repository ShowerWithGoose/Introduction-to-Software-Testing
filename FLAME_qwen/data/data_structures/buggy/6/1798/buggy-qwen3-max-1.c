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
    stack->data[++stack->top] = value; // @@ [Stack top index starts at 0, so incrementing before assignment writes to data[1] on first push, skipping data[0] and potentially causing out-of-bounds access when top reaches MAX_SIZE]
}

int pop(stack *stack) {
    return stack->data[stack->top--]; // @@ [If top is 0 (empty stack), this accesses data[0] and then sets top to -1, which is incorrect logic for an empty stack and may cause underflow or inconsistent state]
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
        if (n == 0) { // @@ [This should be 'else if' to avoid checking pop condition immediately after a push; as written, both push and pop blocks may execute in one loop iteration if n==1, leading to incorrect behavior]
            if (sta.top == 0)
                printf("error ");
            else {
                printf("%d", sta.data [sta.top - 1]); // @@ [Missing space after %d in printf; output format requires a space after each popped element, including the last one]
                sta.top--;
            }
        } else
            break;
    }
    return 0;
}