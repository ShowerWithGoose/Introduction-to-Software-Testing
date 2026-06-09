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
int N, a[15], v[15];

void make(int n)
{
    if (n > N)
    {
        for (int i = 1; i <= N; ++i)
            printf("%d ", a[i]);
        putchar('\n');
        return;
    }
    for (int i = 1; i <= N; ++i)
    {
        if (v[i])
            continue;
        a[n] = i, v[i] = 1;
        make(n + 1);
        v[i] = 0;
    }
}

int main()
{
    scanf("%d", &N);
    make(1);
    return 0;
}


