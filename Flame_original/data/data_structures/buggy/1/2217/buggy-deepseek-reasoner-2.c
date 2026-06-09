#include <stdio.h>

int a[20], m;
int b[20];

void dfs(int k)
{
    if (k == m)

    {
        for (int i = 0; i < m; i++)
            printf("%d", a[i]); // @@ missing space between numbers, should be "%d " to match expected output
        printf("\n");
        return;
    }
    for (int i = 1; i <= m; i++)
    {
        if (b[i] == 0)
        {
            a[k] = i;
            b[i] = 1;
            dfs(k + 1);
            b[i] = 0;
        }
    }
    return;
}

int main()
{
    scanf("%d", &m);
    dfs(0);
    return 0;
}