#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} stack;

void init(stack *stack) {
    stack->top = 0;
} // @@ [The stack is not initialized in main(), so sta.top starts with garbage value, leading to undefined behavior.]

void push(stack *stack, int value) {
    stack->data[++stack->top] = value;
} // @@ [This function is defined but never used; also, it incorrectly increments top before assignment, which would skip index 0 and potentially write beyond bounds if top starts at MAX_SIZE-1.]

int pop(stack *stack) {
    return stack->data[stack->top--];
} // @@ [This function is defined but never used; also, it assumes top points to the current element, but main() uses a different convention (top as count).]

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
        if (n == 0) { // @@ [Should be 'else if' to avoid checking n==0 after handling n==1; otherwise, when n==1, it will also fall through and check n==0, which is incorrect.]
            if (sta.top == 0)
                printf("error ");
            else {
                printf("%d", sta.data [sta.top - 1]); // @@ [Missing space after %d; output format requires a space after each popped value.]
                sta.top--;
            }
        } else
            break;
    }
    return 0;
}