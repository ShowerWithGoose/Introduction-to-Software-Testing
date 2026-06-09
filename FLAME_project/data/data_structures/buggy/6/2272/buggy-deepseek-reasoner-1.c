#include "stdio.h"

void push(int stack[], int data, int top) { // @@ 参数top应为指针，否则无法修改外部栈顶
    if (top >= 99) {
        printf("error ");
        return;
    }
    top++; // @@ 应改为 (*top)++ 以修改外部栈顶
    stack[top] = data;
    return;
}

int pop(int stack[], int top) { // @@ 参数top应为指针，否则无法修改外部栈顶
    if (top <= -1) {
        printf("error ");
        return 0;
    }

    return stack[top]; // @@ 应返回 stack[*top] 并修改 *top
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
            push(stack, data, top); // @@ 应传递 &top
            top++; // @@ 如果push改为传指针，此行冗余，且导致栈顶重复增加

        } else {
            int a = pop(stack, top); // @@ 应传递 &top
            if (a != 0) {
                printf("%d ", a);
            }
            top--; // @@ 如果pop改为传指针，此行冗余，且当栈空时仍执行导致错误
        }
    }
    return 0;
}