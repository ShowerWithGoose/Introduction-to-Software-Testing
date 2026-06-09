/*
4.1 栈操作（栈-基本题）
【问题描述】

假设给定的整数栈初始状态为空，栈的最大容量为100。
从标准输入中输入一组栈操作，按操作顺序输出出栈元素序列。
栈操作：1表示入栈操作，后跟一个整数（不为1、0和-1）为入栈元素；0表示出栈操作；-1表示操作结束。

【输入形式】

从标准输入读取一组栈操作，入栈的整数和表示栈操作的整数之间都以一个空格分隔。

【输出形式】

在一行上按照操作的顺序输出出栈元素序列，以一个空格分隔各元素，最后一个元素后也要有一个空格。
如果栈状态为空时进行出栈操作，或栈满时进行入栈操作，则输出字符串“error”，并且字符串后也要有一空格。
所有操作都执行完后，栈也有可能不为空。

【样例输入】

1 3 1 5 1 7 0 0 1 8 0 1 12 1 13 0 0 0 0 1 90 1 89 0 -1

【样例输出】

7 5 8 13 12 3 error 89

【样例说明】

入栈元素依次为3、5、7，然后有两次出栈动作，所以先输出7和5，这时栈中只有元素3；
之后元素8入栈，又出栈，输出8；随后元素12和13入栈，再进行4次出栈操作，输出13、12和3，
这时栈为空，再进行出栈操作会输出error；最后90和89入栈，进行一次出栈操作，输出89，栈中剩余1个元素。
*/
#include "stdio.h"

void push(int stack[], int data, int top) { // @@ top is passed by value, changes not reflected in main; should use pointer or global variable
    if (top >= 99) { // @@ check uses local copy of top, not the actual top of stack; full condition may be incorrect
        printf("error ");
        return;
    }
    top++; // @@ modifies local top only, does not update main's top
    stack[top] = data; // @@ uses local top, so actual stack top in main remains unchanged
    return;
}

int pop(int stack[], int top) { // @@ top is passed by value; pop only reads top, but error condition uses local copy
    if (top <= -1) {
        printf("error ");
        return 0;
    }

    return stack[top]; // @@ returns element using local top (correct), but caller decrements top unconditionally
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
            push(stack, data, top); // push does not update top, so after push, top remains same
            top++; // @@ this should only happen if push succeeded; currently increments even on error, causing inconsistent state
        } else {
            int a = pop(stack, top);
            if (a != 0) {
                printf("%d ", a);
            }
            top--; // @@ this should be inside the if block; decrements even on pop error (empty stack), making top negative
        }
    }
    return 0;
}