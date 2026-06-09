#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} stack;

void init(stack *stack) {
    stack->top = 0; // @@ [Stack initialization sets top to 0, implying the next push goes to index 0. However, in the push logic later, the code uses sta.data[sta.top] = m; then increments top, which is consistent with top being the count of elements (not the index of the top element). But the pop operation accesses sta.data[sta.top - 1], which is correct only if top is the count. However, the init() function is never called in main(), so the initial value of sta.top is undefined (garbage), leading to undefined behavior.]
}

void push(stack *stack, int value) {
    stack->data[++stack->top] = value; // @@ [This line is never used in main(), so it's dead code. Also, if it were used, it would incorrectly increment top before assigning, assuming top starts at -1. But since main() doesn't use this function and instead manually assigns, this inconsistency isn't directly causing the error, but the lack of initialization is critical.]
}

int pop(stack *stack) {
    return stack->data[stack->top--]; // @@ [This function is never used in main(), so it's dead code. The actual popping is done inline in main().]
}

int main() {
    int n, m;
    stack sta; // @@ [The stack 'sta' is declared but never initialized via init(&sta). Therefore, sta.top contains garbage value, leading to unpredictable behavior during push/pop checks and operations. This is the primary cause of logical errors.]
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
        if (n == 0) { // @@ [This should be 'else if (n == 0)' to avoid checking for pop when n == 1. As written, after handling a push (n == 1), the code will also check the pop condition (n == 0), which is false, so it may not cause immediate harm, but if n were both 1 and 0 (impossible), it's logically incorrect. However, more critically, when n == -1, this 'if' block is skipped, but the 'else break;' belongs to the second 'if', not the first. So if n == 1, after push, it checks second if (false), then skips else. If n == 0, handles pop, skips else. But if n == -1, first if false, second if false, so executes 'else break;' — which is correct. So control flow is actually okay, but using 'else if' is clearer and safer. However, the real issue is uninitialized sta.top.]
            if (sta.top == 0)
                printf("error ");
            else {
                printf("%d", sta.data [sta.top - 1]); // @@ [Missing space after %d. Expected output format requires a space after each popped element, including the last one. This outputs "%d" without a trailing space, violating output format.]
                sta.top--;
            }
        } else
            break;
    }
    return 0;
}