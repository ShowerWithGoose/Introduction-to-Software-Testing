#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define LL long long
int a[100000][2];
int b[100000][2];
int ans[100000][2];
int lena;
int lenb;
int cmp(const void *a, const void *b)
{
    int *ai = (int *)a;
    int *bi = (int *)b;
    return -(*ai - *bi);
}
int main()
{
    char c = 0;
    for (int i = 0; c != '\n'; i++)
    {
        scanf("%d%d", &a[i][1], &a[i][0]);
        c = getchar();
        lena++;
    }
    c = 0;
    for (int i = 0; c != '\n'; i++)
    {
        scanf("%d%d", &b[i][1], &b[i][0]);
        c = getchar();
        lenb++;
    }
    for (int i = 0; i < lena; i++)
    {
        for (int j = 0; j < lenb; j++)
        {
            ans[i * lenb + j][0] = a[i][0] + b[j][0];
            ans[i * lenb + j][1] = a[i][1] * b[j][1];
        }
    }
    qsort(ans, lena * lenb, sizeof(int) * 2, cmp);
    for (int i = 0; i < lena * lenb; i++)
    {
        int x, y;
        x = ans[i][0];
        y = ans[i][1];
        while (i + 1 < lena * lenb && x == ans[i + 1][0])
        {
            i++;
            y += ans[i][1];
        }
        printf("%d %d ", y, x);
    }
    //printf("%d\n", ans[lena * lenb - 1][1]);
    return 0;
}
