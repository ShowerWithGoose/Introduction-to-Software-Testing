#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} stack;

void init(stack *stack) {
    stack->top = 0;
} // @@ [Stack initialization sets top to 0, implying the next push goes to index 0. However, in push and pop logic elsewhere, the code inconsistently treats top as either count of elements or last index.]

void push(stack *stack, int value) {
    stack->data[++stack->top] = value; // @@ [This increments top before assigning, which assumes top starts at -1. But init() sets top to 0, so first push writes to data[1], skipping data[0] and risking overflow when top reaches MAX_SIZE-1.]
}

int pop(stack *stack) {
    return stack->data[stack->top--]; // @@ [This assumes top points to the current top element. But if top was initialized to 0 and never pushed correctly, this may access invalid memory or inconsistent state. Also, this function is never used in main().]
}

int main() {
    int n, m;
    stack sta; // @@ [sta is not initialized via init(), so sta.top contains garbage value, leading to undefined behavior on first operation.]
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
        if (n == 0) { // @@ [Should be 'else if' to avoid checking n == 0 after handling n == 1; otherwise, if n == 1, it will also check n == 0 condition incorrectly.]
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