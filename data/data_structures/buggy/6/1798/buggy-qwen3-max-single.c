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
    stack->data[++stack->top] = value; // @@ [Stack top is initialized to 0, so the first element should be placed at index 0. Using pre-increment writes to data[1] on first push, skipping data[0] and causing out-of-bounds access when top reaches MAX_SIZE-1]
}

int pop(stack *stack) {
    return stack->data[stack->top--]; // @@ [Since top points one past the last valid element (due to incorrect push logic), this accesses invalid memory on first pop. Also, this function is never used in main()]
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
        if (n == 0) { // @@ [Should be 'else if' to avoid checking pop condition after a push or when n == -1. As written, when n == -1, this block executes and causes unintended behavior]
            if (sta.top == 0)
                printf("error ");
            else {
                printf("%d", sta.data [sta.top - 1]); // @@ [Missing space after %d as required by output format: "separated by spaces" and "Ensure there is a space after the last element"]
                sta.top--;
            }
        } else
            break;
    }
    return 0;
}