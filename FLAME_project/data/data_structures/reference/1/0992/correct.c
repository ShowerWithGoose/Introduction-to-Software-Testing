#include <stdio.h>
int n, a[20], book[20];
void dfs(int step)
{
    int i;
    if (step == n + 1)
    {
        for (i = 1; i <= n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }
    for (i = 1; i <= n; i++)
    {
        if (book[i] == 0)
        {
            a[step] = i;
            book[i] = 1;
            dfs(step + 1);
            book[i] = 0;
        }
    }
    return;
}
int main()
{
    scanf("%d", &n);
    dfs(1);
    return 0;
}
