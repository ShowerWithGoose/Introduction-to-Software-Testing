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
    for (i = top; i >= 0; i--) { @@ 错误：问题要求只输出出栈序列，不应输出栈中剩余元素
        printf("%d ", STACK[i]); @@ 错误：同上，多余输出
    }

    printf("\n"); // 添加换行符 @@ 错误：输出格式未要求换行，且导致输出与预期不符

return 0;
}