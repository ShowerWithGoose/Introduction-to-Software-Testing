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
    return stack->data[stack->top--]; // @@ [This function is defined but never used; also, it assumes top points to the current element, but due to the off-by-one error in push, behavior is inconsistent]
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
        if (n == 0) { // @@ [Should be 'else if' to avoid checking n == 0 after handling n == 1; if input is 1, both blocks may execute incorrectly]
            if (sta.top == 0)
                printf("error ");
            else {
                printf("%d", sta.data [sta.top - 1]); // @@ [Missing space after %d as required by output format: should be "%d "]
                sta.top--;
            }
        } else
            break;
    }
    return 0;
}