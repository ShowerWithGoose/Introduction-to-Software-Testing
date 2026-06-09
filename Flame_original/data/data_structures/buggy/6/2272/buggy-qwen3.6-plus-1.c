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

void push(int stack[], int data, int top) { // @@ top is passed by value, so modifications inside the function do not affect the top variable in main
    if (top >= 99) {
        printf("error ");
        return;
    }
    top++; // @@ increments the local copy of top, not the one in main
    stack[top] = data; // @@ uses local top, but main also increments top, causing off-by-one indexing and double increment
    return;
}

int pop(int stack[], int top) { // @@ top is passed by value, disconnecting function logic from main's stack pointer
    if (top <= -1) {
        printf("error ");
        return 0;
    }

    return stack[top]; // @@ returns value but does not update top; main unconditionally decrements top, causing double decrement
}

int main() {
    int stack[100] = {0};
    int top = -1;
    int op;
    while (scanf("%d", &op) != -1) { // @@ scanf returns the number of successfully read items, not the value read; should check == 1 or != EOF
        // 1表示入栈操作，后跟一个整数（不为1、0和-1）为入栈元素；0表示出栈操作；-1表示操作结束。
        if (op == -1) {
            break;
        } else if (op == 1) {
            int data;
            scanf("%d", &data);
            push(stack, data, top); // @@ passes top by value, function cannot update the actual stack pointer
            top++; // @@ manually increments top, leading to double increment since push already incremented its local copy

        } else {
            int a = pop(stack, top); // @@ passes top by value
            if (a != 0) { // @@ relies on return value 0 to indicate error, which is logically flawed; should check stack empty state directly
                printf("%d ", a);
            }
            top--; // @@ manually decrements top, leading to double decrement and incorrect stack state
        }
    }
    return 0;
}