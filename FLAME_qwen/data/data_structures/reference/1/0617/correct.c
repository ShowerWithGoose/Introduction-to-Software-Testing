#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define mian main
typedef long long ll;
typedef unsigned long long ull;
#define forsx(i, a, b) for (int i = (a); i < (b); ++i)
#define forjx(i, a, b) for (int i = (a); i > (b); --i)

#define ElementType int
ElementType max(ElementType a, ElementType b)
{
    return a > b ? a : b;
}

ElementType min(ElementType a, ElementType b)
{
    return a < b ? a : b;
}
int ans[15];
void dfs(int a, int b);
int main(int argc, const char *argv[])
{
    int q;
    scanf("%d", &q);
    dfs(0, q);
    return 0;
}
void dfs(int a, int b)
{
    if (a == b)
    {
        for (int i = 0; i < b; i++)
        {
            if (i)
                printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    for (int i = 1; i <= b; i++)
    {
        int used = 1;
        for (int j = 0; j < a; j++)
        {
            if (ans[j] == i)
                used = 0;
        }
        if (used == 1)
        {
            ans[a] = i;
            dfs(a + 1, b);
        }
    }
}

