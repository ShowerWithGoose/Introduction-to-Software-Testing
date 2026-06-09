#define   _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
int n = 0;
int isused[10];
int num[10] = { 0 };
void dfs(int x)
{
    if (x > n)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d", num[i]); // @@ Missing space between numbers; should be "%d " to match expected output format with spaces.
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