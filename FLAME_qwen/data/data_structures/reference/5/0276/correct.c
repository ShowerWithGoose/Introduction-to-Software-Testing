#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct
{
    int a, p;
} fx;
fx a[100], b[100], c[5000];
int cmp_fx(const void *_a, const void *_b) //参数格式固定
{
    fx *a = (fx *)_a; //强制类型转换
    fx *b = (fx *)_b;
    return b->p - a->p;
}
int cnt, x, y;
int main()
{
    do
    {
        scanf("%d%d", &a[x].a, &a[x].p);
        x++;
    } while (getchar() != '\n');
    do
    {
        scanf("%d%d", &b[y].a, &b[y].p);
        y++;
    } while (getchar() != '\n');
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
        {
            int k = 0;
            for (; k < cnt && a[i].p + b[j].p != c[k].p; k++)
                ;
            c[k].a += a[i].a * b[j].a;
            if (k == cnt)
                c[cnt++].p = a[i].p + b[j].p;
        }
    qsort(c, cnt, sizeof(fx), cmp_fx);
    for (int i = 0; i < cnt; i++)
        if (c[i].a)
            printf("%d %d ", c[i].a, c[i].p);
    return 0;
}



