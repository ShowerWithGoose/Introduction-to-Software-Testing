#define   _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
int n = 0;
int isused[10]; // @@ Array size is too small. When N=10, accessing index 10 causes out-of-bounds error. Should be at least 11.
int num[10] = { 0 }; // @@ Array size is too small. When N=10, accessing index 10 causes out-of-bounds error. Should be at least 11.
void dfs(int x)
{
    if (x > n)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d", num[i]); // @@ Missing space separator between integers as required by the output format. Should be printf("%d ", num[i]);.
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