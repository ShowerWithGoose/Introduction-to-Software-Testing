#include <stdio.h>
#include <stdlib.h>
//多项式乘法
typedef struct f
{
    int a;
    int n;
} F;

int cmp(const void *, const void *);

int main()
{
    F f1[100], f2[100], fx[100];
    int p, q, i = 0, j = 0, k = 0;
    char c;
    while ((scanf("%d%d%c", &p, &q, &c) != EOF) && (c != '\n'))
    { //读入第一个多项式
        f1[i].a = p;
        f1[i].n = q;
        i++;
    }
    f1[i].a = p;
    f1[i].n = q;
    while ((scanf("%d%d%c", &p, &q, &c) != EOF) && (c != '\n'))
    { //读入第二个多项式
        f2[j].a = p;
        f2[j].n = q;
        j++;
    }
    f2[j].a = p;
    f2[j].n = q;
    for (int t = 0; t <= i; t++)
    {
        for (int m = 0; m < j + 1; m++)
        {
            fx[k].a = f1[t].a * f2[m].a;
            fx[k].n = f1[t].n + f2[m].n;
            k++;
        }
    }
    qsort(fx, k, sizeof(F), cmp); //对指数进行升序排列
    for (int t = 0; t < k; t++)
    {
        if (fx[t].n == fx[t + 1].n)
        { //合并指数相同的项
            fx[t + 1].a += fx[t].a;
            fx[t].a = 0;
        }
    }
    for (int t = k - 1; t >= 0; t--)
    {
        if (fx[t].a != 0)
            printf("%d %d ", fx[t].a, fx[t].n); //反向输出
        else
            continue;
    }
    return 0;
}

int cmp(const void *p1, const void *p2)
{
    F *a = (F *)p1;
    F *b = (F *)p2;
    return a->n - b->n;
}
