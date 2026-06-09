#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAX_SIZE 100
int main()
{
    int STACK[MAX_SIZE];
    int top = -1;
    int operation, value, i;

    // 读取操作序列
    while (1) {
        scanf("%d", &operation);
        if (operation == -1) {
            break; // 结束输入
        } else if (operation == 1) {
            scanf("%d", &value);
            if (top >= MAX_SIZE - 1) {
                printf("error ");
            } else {
                STACK[++top] = value; // 入栈
            }
        } else if (operation == 0) {
            if (top == -1) {
                printf("error ");
            } else {
                printf("%d ", STACK[top--]); // 出栈
            }
        }
    }

    // 输出栈中剩余的元素
    for (i = top; i >= 0; i--) {
        printf("%d ", STACK[i]);
    } // @@ [The problem requires only the sequence of popped elements during operations. This loop incorrectly outputs remaining stack elements after processing all operations, which is not part of the expected output.]

    printf("\n"); // 添加换行符 // @@ [The expected output does not include a newline; it should end with a space after the last element and nothing else. This newline causes formatting mismatch.]

return 0;
}