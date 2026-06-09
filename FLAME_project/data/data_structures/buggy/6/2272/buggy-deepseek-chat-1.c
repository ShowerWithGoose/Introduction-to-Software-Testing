#include "stdio.h"

void push(int stack[], int data, int top) { // @@ [The function receives 'top' by value, so modifications to 'top' inside the function do not affect the 'top' variable in main(). The stack's top index is never updated globally, causing all pushes to overwrite the same position and the stack to never be considered full.]
    if (top >= 99) {
        printf("error ");
        return;
    }
    top++;
    stack[top] = data;
    return;
}

int pop(int stack[], int top) { // @@ [Similar to push, 'top' is passed by value. The function cannot decrement the global top index. Additionally, the function returns the popped value but does not decrement top in main() correctly because the condition 'if (a != 0)' is flawed—0 is a valid data value, so legitimate pops of 0 would be skipped.]
    if (top <= -1) {
        printf("error ");
        return 0;
    }

    return stack[top];
}

int main() {
    int stack[100] = {0};
    int top = -1;
    int op;
    while (scanf("%d", &op) != -1) {
        // 1表示入栈操作，后跟一个整数（不为1、0和-1）为入栈元素；0表示出栈操作；-1表示操作结束。
        if (op == -1) {
            break;
        } else if (op == 1) {
            int data;
            scanf("%d", &data);
            push(stack, data, top);
            top++; // @@ [This increment is incorrect because push() already increments its local copy of top. The global top is incremented here without considering the push function's internal logic, leading to an off-by-one error and skipping stack positions.]

        } else {
            int a = pop(stack, top);
            if (a != 0) { // @@ [This condition incorrectly treats 0 as an error indicator, but 0 can be a legitimate data value pushed onto the stack. Valid pops of 0 will be ignored and not printed.]
                printf("%d ", a);
            }
            top--; // @@ [This decrement is incorrect because pop() does not modify the global top. The global top is decremented here unconditionally, even when the stack is empty, causing the top index to go below -1 and corrupting subsequent operations.]
        }
    }
    return 0;
}