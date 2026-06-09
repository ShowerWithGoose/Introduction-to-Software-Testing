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
                sta.data[sta.top ] = m; // @@ Error: This line assigns to the current top index, but the stack uses 0-based indexing with top=0 meaning empty. The correct approach is to assign at sta.top and then increment, but the order is wrong here. It should be sta.data[sta.top] = m; followed by sta.top++, but the current code has a space in "sta.top ]" which is a syntax error.
                sta.top++;
            }
        }
        if (n == 0) {
            if (sta.top == 0)
                printf("error ");
            else {
                printf("%d", sta.data [sta.top - 1]); // @@ Error: There is an extra space in "sta.data [sta.top - 1]" which is a syntax error. Additionally, the output format requires a space after each popped element, but this prints without a trailing space.
                sta.top--;
            }
        } else
            break;
    }
    return 0;
}