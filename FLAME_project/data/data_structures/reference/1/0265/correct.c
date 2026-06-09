#include <stdlib.h>
#include <stdio.h>
int a[114514], n, book[114514];
void dfs(int step)
{
    int i;
    if (step == n + 1)
    {
        for (i = 1; i <= n; i++)
            printf("%d ", a[i]);
        putchar('\n');
        return;
    }
    for (i = 1; i <= n; i++)
    {
        if (!book[i])
        {
            a[step] = i;
            book[i] = 1;
            dfs(step + 1);
            book[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    dfs(1);
    return 0;
}
