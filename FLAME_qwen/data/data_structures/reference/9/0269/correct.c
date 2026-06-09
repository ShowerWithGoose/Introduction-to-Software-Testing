#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int i, j, n;
struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
} Line[105];
int cmp1(const void *p1, const void *p2)
{
    struct line *a = (struct line *)p1;
    struct line *b = (struct line *)p2;
    return a->x1 - b->x1;
}
int cmp2(const void *p1, const void *p2)
{
    struct line *a = (struct line *)p1;
    struct line *b = (struct line *)p2;
    return b->num - a->num;
}
int main()
{
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &Line[i].x1, &Line[i].y1, &Line[i].x2, &Line[i].y2);
        Line[i].num = 1;
    }
    qsort(Line, n, sizeof(Line[0]), cmp1);
    for (i = 0; i < n; i++)
    {
        if (Line[i].num==0)
            continue;
        for (j = i + 1; j < n; j++)
        {
            if (Line[i].x2 == Line[j].x1 && Line[i].y2 == Line[j].y1)
            {
                Line[i].x2 = Line[j].x2;
                Line[i].y2 = Line[j].y2;
                Line[i].num++;
                Line[j].num = 0;
            }
        }
    }
    qsort(Line, n, sizeof(Line[0]), cmp2);
    printf("%d %d %d", Line[0].num, Line[0].x1, Line[0].y1);
    return 0;
}
