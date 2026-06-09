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
    stack sta; // @@ stack uninitialized; top contains garbage, should call init(&sta);
    while (~scanf("%d", &n)) {
        if (n == 1) {
            if (sta.top == MAX_SIZE) // @@ sta.top uninitialized leads to undefined behavior;
                printf("error ");
            else {
                scanf("%d", &m);
                sta.data[sta.top ] = m;
                sta.top++;
            }
        }
        if (n == 0) {
            if (sta.top == 0) // @@ sta.top uninitialized leads to undefined behavior;
                printf("error ");
            else {
                printf("%d", sta.data [sta.top - 1]); // @@ missing trailing space after number, expected "567 ";
                sta.top--;
            }
        } else // @@ this else belongs to the second if, causing loop to break on any n != 0 (e.g., push operation or end marker -1); correct logic should handle n==1 and n==-1 separately;
            break;
    }
    return 0;
}