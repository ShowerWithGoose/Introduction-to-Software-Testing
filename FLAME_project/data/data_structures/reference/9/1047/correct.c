#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int x1;
    int x2;
    int y1;
    int y2;
} Line;
Line l[100];
int cmp(const void *p1, const void *p2)
{
    Line *x = (Line *)p1;
    Line *y = (Line *)p2;
    return x->x1 < y->x2 ? -1 : 1;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d%d", &l[i].x1, &l[i].y1, &l[i].x2, &l[i].y2);
    qsort(l + 1, n, sizeof(l[0]), cmp);
    int maxn = 0, max[2];
    for (int i = 1; i <= n; i++)
    {
        int num = 1, end[2] = {l[i].x2, l[i].y2};
        for (int j = i + 1; j <= n; j++)
        {
            if (l[j].x1 == end[0] && l[j].y1 == end[1])
            {
                end[0] = l[j].x2;
                end[1] = l[j].y2;
                num++;
            }
        }
        if (num > maxn)
        {
            maxn = num;
            max[0] = l[i].x1;
            max[1] = l[i].y1;
        }
    }
    printf("%d %d %d", maxn, max[0], max[1]);
    return 0;
}


