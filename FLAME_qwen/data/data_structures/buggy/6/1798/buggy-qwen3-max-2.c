#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} stack;

void init(stack *stack) {
    stack->top = 0;
} // @@ [Stack initialization sets top to 0, implying top points to the next available slot. However, push/pop logic inconsistently treats top as either count or index.]

void push(stack *stack, int value) {
    stack->data[++stack->top] = value; // @@ [Pre-increment causes writing to data[1] on first push when top starts at 0, skipping data[0]; also risks overflow beyond MAX_SIZE-1]
}

int pop(stack *stack) {
    return stack->data[stack->top--]; // @@ [This function is defined but never used; main implements its own pop logic, leading to inconsistency]
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
        if (n == 0) { // @@ [Should be 'else if' to avoid checking n==0 after handling n==1; if input is 1, this block may incorrectly execute if n later equals 0 in same iteration (though not possible here due to single read), but more critically, after break condition]
            if (sta.top == 0)
                printf("error ");
            else {
                printf("%d", sta.data [sta.top - 1]); // @@ [Missing space after %d; output format requires space after each popped element including last]
                sta.top--;
            }
        } else
            break;
    }
    return 0;
}