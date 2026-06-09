#define   _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
int n = 0;
int isused[10]; // @@ 数组大小不足，当N=10时，索引10越界，应至少为11
int num[10] = { 0 }; // @@ 同上，数组大小不足
void dfs(int x)
{
    if (x > n)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d", num[i]); // @@ 输出缺少空格，不符合题目要求的每个整数之间用空格分隔
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (0 == isused[i])
        {
            isused[i] = 1;
            num[x] = i;
            dfs(x + 1);
            isused[i] = 0;
            num[x] = 0;
        }
    }
}
int main()
{
    scanf("%d", &n);
    dfs(1);
    return 0;
}