#include <stdio.h>
#include <stdlib.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))
typedef struct
{
    int n, x1, y1, x2, y2;
} line;
int cmp_line(const void *_a, const void *_b)
{
    line *a = (line *)_a;
    line *b = (line *)_b;
    return a->x1 - b->x1;
}
int n, cnt, x, y;
line l[102];
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d%d%d", &l[cnt].x1, &l[cnt].y1, &l[cnt].x2, &l[cnt].y2);
        l[cnt++].n++;
    }
    qsort(l, cnt, sizeof(l[0]), cmp_line);
    for (int i = 0; i < cnt; i++)
        for (int j = 0; j < cnt; j++)
        {
            if (l[i].x1 == l[j].x2 && l[i].y1 == l[j].y2)
                l[i].n = l[j].n = Max(l[i].n, l[j].n) + 1, l[i].x1 = l[j].x1, l[j].x2 = l[i].x2, l[i].y1 = l[j].y1, l[j].y2 = l[i].y2;
            else if (l[i].x2 == l[j].x1 && l[i].y2 == l[j].y1)
                l[i].n = l[j].n = Max(l[i].n, l[j].n) + 1, l[i].x2 = l[j].x2, l[j].x1 = l[i].x1, l[i].y2 = l[j].y2, l[j].y1 = l[i].y1;
        }
    for (int i = 0; i < cnt; i++)
        if (l[i].n > n)
            n = l[i].n, x = l[i].x1, y = l[i].y1;
    printf("%d %d %d", n, x, y);
    return 0;
}


