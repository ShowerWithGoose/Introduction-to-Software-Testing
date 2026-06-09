#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
    int flag; //存线段次数
} a[100];
int carol(const void *m1, const void *m2)
{
    struct line *n1 = (struct line *)m1;
    struct line *n2 = (struct line *)m2;
    return n1->x1 - n2->x1;
}
int main()
{
    int n;
    int i, j, k;
    int ans;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
        a[i].flag = 1;
    }
    // x排序捏
    qsort(a, n, sizeof(struct line), carol);
    putchar('\n');
    /*for (i = 0; i < n; i++)
    {
        printf("%d %d %d %d\n", a[i].x1, a[i].y1, a[i].x2, a[i].y2);
    }*/
    // printf("-------%d", a[4].flag);

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i].x2 == a[j].x1 && a[i].y2 == a[j].y1)
            {
                a[i].x2 = a[j].x2;
                a[i].y2 = a[j].y2; //换末尾
                a[i].flag++;
            }
            else if (a[i].x2 == a[j].x2 && a[i].y2 == a[j].y2)
            {
                a[i].x2 = a[j].x1;
                a[i].y2 = a[j].y1;
                a[i].flag++;
            }
        }
    }
    ans = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i].flag > a[ans].flag)
            ans = i;
    }
    printf("%d %d %d", a[ans].flag, a[ans].x1, a[ans].y1);

    getchar();
    return 0;
}

