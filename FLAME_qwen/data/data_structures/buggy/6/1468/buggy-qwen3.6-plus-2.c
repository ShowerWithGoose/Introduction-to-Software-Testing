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

    // 输出栈中剩余的元素 // @@ The problem specification only requires outputting popped elements and error messages, not the remaining elements in the stack.
    for (i = top; i >= 0; i--) { // @@ This loop incorrectly outputs remaining stack elements, which violates the output format requirement.
        printf("%d ", STACK[i]); // @@ Should be removed as it produces incorrect output not requested by the problem.
    } // @@ End of erroneous loop.

    printf("\n"); // 添加换行符

return 0;
}