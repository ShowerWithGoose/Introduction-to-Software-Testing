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
    for (i = top; i >= 0; i--) { // @@ This loop prints remaining stack elements, which is not required; only popped elements should be output.
        printf("%d ", STACK[i]); // @@ This prints a remaining element, causing extra output beyond the expected popped sequence.
    }

    printf("\n"); // @@ This newline is unnecessary; the problem expects only the popped sequence with trailing space, no extra newline.

return 0;
}