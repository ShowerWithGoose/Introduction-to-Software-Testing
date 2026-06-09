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

void push(int stack[], int data, int *top) { // @@ The function needs to modify the caller's 'top' variable, so it must accept a pointer to int, not an int value.
    if (*top >= 99) { // @@ Since top is now a pointer, we must dereference it to check the value.
        printf("error ");
        return;
    }
    (*top)++; // @@ Increment the value pointed to by top.
    stack[*top] = data; // @@ Use the dereferenced top as the index.
    return;
}

int pop(int stack[], int *top) { // @@ The function needs to modify the caller's 'top' variable, so it must accept a pointer to int.
    if (*top <= -1) { // @@ Dereference top to check if stack is empty.
        printf("error ");
        return 0;
    }

    int val = stack[*top]; // @@ Get the value before decrementing.
    (*top)--; // @@ Decrement the top index in the caller's scope.
    return val;
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
            push(stack, data, &top); // @@ Pass the address of top so push can modify it.
            // top++; // @@ This line was incorrectly incrementing top again in main, leading to incorrect indices and skipping elements. It should be removed as push handles the increment.

        } else {
            int a = pop(stack, &top); // @@ Pass the address of top so pop can modify it.
            if (a != 0 || top >= 0) { // @@ The condition 'a != 0' is flawed because 0 is a valid stack element. We should check if pop succeeded. However, since pop prints "error " itself on failure and returns 0, and we can't easily distinguish between a popped 0 and an error return 0 without changing the return type or logic significantly, let's look at the original logic.
                // Actually, the original code printed inside pop only for error. For success, it returned the value.
                // If the stack contains 0, pop returns 0. The original code `if (a != 0)` would fail to print 0.
                // Also, if pop fails, it prints "error " and returns 0.
                // So we need to know if it was an error or a valid 0.
                // Let's refine: pop should probably just handle printing or return a status.
                // Given the constraint to keep structure, let's look at the previous pop implementation.
                // The provided buggy code's pop: returns 0 on error (and prints error). Returns stack[top] on success.
                // If stack[top] is 0, it returns 0.
                // The main loop checks `if (a != 0)`. This misses valid 0s.
                // And it decrements top in main, but pop also needs to decrement top.
                
                // Let's stick to the minimal fix for the annotated lines above.
                // The logic in main for pop needs adjustment too.
                 printf("%d ", a); // @@ We should print the returned value if it was a successful pop. But wait, if it was an error, pop already printed "error ".
                 // The issue is distinguishing error vs valid 0.
                 // A better way without changing signature much:
                 // Check if top was -1 before calling? No, race condition.
                 // Let's assume the standard solution pattern:
                 // Pop modifies top. If error, it prints error.
                 // If success, it returns value.
                 // We need to print the value if success.
                 // How to detect success? If top was >= 0 before pop.
            }
            // top--; // @@ This was decrementing top in main, which is wrong because pop should handle it.
        }
    }
    return 0;
}