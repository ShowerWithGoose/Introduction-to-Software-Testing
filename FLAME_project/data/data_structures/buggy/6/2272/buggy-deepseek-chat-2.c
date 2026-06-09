#include "stdio.h"

void push(int stack[], int data, int top) { // @@ The function receives top by value, so modifications to top inside the function do not affect the top variable in main. This causes the stack top pointer to never be updated correctly.
    if (top >= 99) {
        printf("error ");
        return;
    }
    top++;
    stack[top] = data;
    return;
}

int pop(int stack[], int top) { // @@ The function receives top by value, so the decrement of top in main is incorrect because the function does not return the new top value. Also, the function does not decrement top, so the stack pointer is not properly managed.
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
            push(stack, data, top); // @@ After push returns, top in main is not updated, so the stack pointer remains unchanged.
            top++; // @@ This increments top after push, but push already incremented its local copy, so top is incremented twice for each push, causing incorrect stack management.

        } else {
            int a = pop(stack, top); // @@ pop does not decrement top, so the same element is popped repeatedly.
            if (a != 0) {
                printf("%d ", a);
            }
            top--; // @@ This decrements top after pop, but pop did not decrement its local copy, so the stack pointer is decremented without actually removing the element.
        }
    }
    return 0;
}