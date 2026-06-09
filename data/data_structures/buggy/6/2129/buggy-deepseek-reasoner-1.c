#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int i, n, m, j, stack[100], top = -1;
    scanf("%d", &n); // @@ 只读取第一个操作数，没有在循环中持续读取后续操作，导致无法处理完整输入序列
    while (n != EOF) // @@ 条件错误：n是整数值，不应与EOF比较；且循环内没有更新n，将导致无限循环
    {
        if (n == 1) // @@ push操作处理后缺少读取下一个操作数，n不会更新，循环无法前进
        {
            scanf("%d", &m);
            if (top == 99)
            {
                printf("error ");
            }
            else
            {
                stack[++top] = m;
            }
        }
        if (n == 0) // @@ pop操作处理后缺少读取下一个操作数，n不会更新，循环无法前进
        {
            if (top == -1)
            {
                printf("error ");
            }
            else
            {
                printf("%d", stack[top]); // @@ 缺少空格，不符合输出格式要求（每个元素后应有空格）
                stack[top] = 0;
                top--;
            }
        }
    } // @@ 循环体末尾缺少读取下一个操作数的语句，导致n始终为初始值

    return 0;
}