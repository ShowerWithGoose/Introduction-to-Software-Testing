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
    stack->data[++stack->top] = value; // @@ [Stack overflow: top is incremented before assignment, so when top is 99 (last valid index), it becomes 100 and writes out of bounds. Also, init sets top=0 implying top is count, but this uses top as index after increment.]
}

int pop(stack *stack) {
    return stack->data[stack->top--]; // @@ [Stack underflow: if top is 0 (empty), accessing data[0] is invalid since no element was pushed yet. Also inconsistent with main logic which uses top as count.]
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
        if (n == 0) { // @@ [Logic error: should be 'else if' to avoid checking n==0 after handling n==1, because if n==1, this block will also execute incorrectly.]
            if (sta.top == 0)
                printf("error ");
            else {
                printf("%d", sta.data [sta.top - 1]); // @@ [Missing space after %d; output format requires space after each popped value.]
                sta.top--;
            }
        } else
            break;
    }
    return 0;
}