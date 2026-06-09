#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int st[100] = {};
int ar[100] = {};
int n;
void dfs(int x)
{
    int i;
    if (x > n)
    {
        for (i = 1; i <= n; i++)
        {
            printf("%d", ar[i]); // @@ Missing space between numbers; should be "%d " to match expected output format.
        }
        printf("\n");
    }
    for (i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            st[i] = 1;
            ar[x] = i;
            dfs(x + 1);

            st[i] = 0;
            ar[x] = 0;
        }
    }
}
int main()
{
    scanf("%d", &n);
    dfs(1);
    return 0;
}