#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct point
{
    int x;
    int y;
};
struct line
{
    struct point d1;
    struct point d2;
    int lenth;
};
int cmp2(const void *p1, const void *p2)
{
    if ((*(struct line *)p1).d1.y > (*(struct line *)p2).d1.y)
        return 1;
    if ((*(struct line *)p1).d1.y == (*(struct line *)p2).d1.y)
        return 0;
    if ((*(struct line *)p1).d1.y < (*(struct line *)p2).d1.y)
        return -1;
}
int cmp1(const void *p1, const void *p2)
{
    if ((*(struct line *)p1).d1.x > (*(struct line *)p2).d1.x)
        return 1;
    if ((*(struct line *)p1).d1.x == (*(struct line *)p2).d1.x)
        cmp2(p1, p2);
    if ((*(struct line *)p1).d1.x < (*(struct line *)p2).d1.x)
        return -1;
}
int main()
{
    struct line l[102];
    int i, n, j, t, max = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf(" %d%d%d%d", &l[i].d1.x, &l[i].d1.y, &l[i].d2.x, &l[i].d2.y);
    }
    for (i = 0; i < n; i++)
    {
        l[i].lenth = 1;
    }
    qsort(l, n, sizeof(l[0]), cmp1);
    for (i = n; i >= 0; i--)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            else if (l[j].d2.x == l[i].d1.x && l[j].d2.y == l[i].d1.y)
            {
                l[j].lenth += l[i].lenth;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (l[i].lenth > max)
        {
            max = l[i].lenth;
            t = i;
        }
    }
    printf("%d %d %d", max, l[t].d1.x, l[t].d1.y);
    return 0;
}
