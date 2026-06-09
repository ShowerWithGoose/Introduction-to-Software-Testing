#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
int n, ans[15], used[15];

void make(int step)
{
    if (step > n)
    {
        for (int i = 1; i <= n; ++i)
            printf("%d ", ans[i]);
        putchar('\n');
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (used[i])
            continue;
        ans[step] = i, used[i] = 1;
        make(step + 1);
        used[i] = 0;
    }
}

int main()
{
    scanf("%d", &n);
    make(1);
    return 0;
}


