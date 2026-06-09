#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <memory.h>
#define mian main
typedef long long ll;
typedef unsigned long long ull;
#define forsx(i, a, b) for (int i = (a); i < (b); ++i)
#define forjx(i, a, b) for (int i = (a); i > (b); --i)

#define ElementType int
#define __MAX__ 105
ElementType max(ElementType a, ElementType b)
{
    return a > b ? a : b;
}

ElementType min(ElementType a, ElementType b)
{
    return a < b ? a : b;
}

typedef struct
{
    int x_s;
    int y_s;
    int x_e;
    int y_e;
    int cnt;
} res, *pRes;
res ans[__MAX__];
int cmpfunc(const void *a, const void *b)
{
    pRes aa = (pRes)a;
    pRes bb = (pRes)b;
    if (aa->x_s != bb->x_s)
        return (aa->x_s > bb->x_s) ? (1) : (-1);
    else
        return (aa->y_s > bb->y_s) ? (1) : (-1);
}
int main(int argc, const char *argv[])
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d %d %d %d", &ans[i].x_s, &ans[i].y_s, &ans[i].x_e, &ans[i].y_e);
        ans[i].cnt = 1;
    }
    qsort(ans, N, sizeof(ans[0]), cmpfunc);
    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (ans[j].x_e == ans[i].x_s && ans[j].y_e == ans[i].y_s)
            {
                ans[j].x_e = ans[i].x_e;
                ans[j].y_e = ans[i].y_e;
                ans[j].cnt += ans[i].cnt;
            }
        }
    }
    int max = -1, ansx, ansy;
    for (int i = 0; i < N; ++i)
    {
        if (ans[i].cnt > max)
        {
            max = ans[i].cnt;
            ansx = ans[i].x_s;
            ansy = ans[i].y_s;
        }
    }
    printf("%d %d %d\n", max, ansx, ansy);
    return 0;
}
