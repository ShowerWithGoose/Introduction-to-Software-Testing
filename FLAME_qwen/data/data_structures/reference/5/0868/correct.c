#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Poly
{
    int coe;
    int index;
} POLY;

POLY a[2000], b[2000], c[2000];

int cmp(const void *p1, const void *p2)
{
    POLY *a = (POLY *)p1, *b = (POLY *)p2;
    return b->index - a->index;
}

int main()
{
    int len_a = 0, len_b = 0;
    char ch;
    do//读取两行多项式
    {
        scanf("%d%d%c", &a[len_a].coe, &a[len_a].index, &ch);
        len_a++;
    } while (ch != '\n');
    do
    {
        scanf("%d%d%c", &b[len_b].coe, &b[len_b].index, &ch);
        len_b++;
    } while (ch != '\n');
    qsort(a, len_a, sizeof(POLY), cmp);//给两行多项式排序
    qsort(b, len_b, sizeof(POLY), cmp);
    int len_c = 0;
    for (int i=0; i < len_a; i++)//计算多项式并存到c中
    {
        for (int j=0; j < len_b; j++)
        {
            c[len_c].coe = a[i].coe * b[j].coe;
            c[len_c].index = a[i].index + b[j].index;
            len_c++;
        }
    }
    qsort(c, len_c, sizeof(POLY), cmp);//给c排序
    for (int i = 0; i < len_c-1; i++)//合并同类项
    {
        if (c[i].index == c[i + 1].index && c[i].index != -1)
        {
            c[i + 1].coe += c[i].coe;
            c[i].coe = 0;
            c[i].index = -1;//将加完后的指数设置为-1
        }
    }
    qsort(c, len_c, sizeof(POLY), cmp);//给c排序
    for (int i = 0; i < len_c && c[i].index >= 0; i++)//输出到指数为负数之前
        if (c[i].coe != 0)
            printf("%d %d ", c[i].coe, c[i].index);
    return 0;
}
