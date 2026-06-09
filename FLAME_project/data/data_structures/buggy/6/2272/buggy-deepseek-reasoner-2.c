#include "stdio.h"

void push(int stack[], int data, int top) { // @@ top should be passed by pointer to modify main's top.
    if (top >= 99) {
        printf("error ");
        return;
    }
    top++; // @@ local increment doesn't affect main's top; main does its own increment.
    stack[top] = data;
    return;
}

int pop(int stack[], int top) { // @@ top should be passed by pointer.
    if (top <= -1) {
        printf("error ");
        return 0;
    }

    return stack[top]; // @@ should also decrement top before returning or via pointer.
}

int main() {
    int stack[100] = {0};
    int top = -1;
    int op;
    while (scanf("%d", &op) != -1) { // @@ scanf returns number of items; should compare to EOF or use 1.
        // 1表示入栈操作，后跟一个整数（不为1、0和-1）为入栈元素；0表示出栈操作；-1表示操作结束。
        if (op == -1) {
            break;
        } else if (op == 1) {
            int data;
            scanf("%d", &data);
            push(stack, data, top); // @@ push does not update main's top; unconditional call.
            top++; // @@ should only increment if push succeeded.

        } else {
            int a = pop(stack, top); // @@ pop does not update main's top.
            if (a != 0) {
                printf("%d ", a);
            }
            top--; // @@ should only decrement if pop succeeded.
        }
    }
    return 0;
}