#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[10], b[10] = {0};
int main()
{
    scanf("%d", &n);
    dfs(0);
    return 0;
}
void dfs(int step)
{
    if (step == n)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[j]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 0)
        {
            a[step] = i + 1;
            b[i] = 1;
            dfs(step + 1);
            b[i] = 0;
        }
    }
}
