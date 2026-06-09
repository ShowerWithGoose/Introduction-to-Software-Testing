#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct link
{
    int bx;
    int by;
    int ex;
    int ey;
    int num;
} link[100];
int cmp(const void *a, const void *b)
{
    struct link *c = (link *)a;
    struct link *d = (link *)b;
    if (c->bx != d->bx)
        return d->bx - c->bx;
    else
        return d->by - c->by;
}
int main()
{
    link link;
    int n, flag = 0;
    scanf("%d", &n);
    int i, j;
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &link[i].bx, &link[i].by, &link[i].ex, &link[i].ey);
        link[i].num = 1;
    }
    qsort(link, n, sizeof(link[0]), cmp);
    for (i = 0; i < n - 1; i++)
    {
        for (j = i; j < n - 1; j++)
        {
            if (link[i].bx == link[j + 1].ex && link[i].by == link[j + 1].ey)
            {
                link[j + 1].num += link[i].num;
                break;
            }
        }
    }
    int max = 0;
    for (i = 0; i < n; i++)
    {
        if (link[i].num > max)
        {
            max = link[i].num;
            flag = i;
        }
    }
    printf("%d %d %d", max, link[flag].bx, link[flag].by);
    return 0;
}
