#include <stdio.h>
void DfsFullPermutation(int *a, int *b, int n, int depth) //全排列递归函数
{
    int i;
    if (depth == n + 1) //如果深度与要求输入整数匹配
    {
        for (i = 1; i <= n; i++)
        {
            printf("%d ", a[i]); //输出a中的数字
        }
        printf("\n");
        return;
    }
    for (i = 1; i <= n; i++)
    {
        if (b[i] == 0) // b数字判断该数字是否用过
        {
            b[i] = 1;                               //使用过的数，b变为1
            a[depth] = i;                           // a在该深度的数为未使用过的数
            DfsFullPermutation(a, b, n, depth + 1); //继续确定下一个数
            b[i] = 0;                               //回溯的时候一定要把上次使用过的数变为没有使用过
        }
    }
}
int main()
{
    int n, i;
    int a[100] = {0};
    int b[100] = {0};
    scanf("%d", &n);
    DfsFullPermutation(a, b, n, 1);
    return 0;
}

