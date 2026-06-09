#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Poly
{
    int coe;
    int power_a;
} POLY;

POLY factor_a[2000], factor_b[2000], factor_c[2000];

int cmp(const void *p1, const void *p2)
{
    POLY *factor_a = (POLY *)p1, *factor_b = (POLY *)p2;
    return factor_b->power_a - factor_a->power_a;
}

int main()
{
    int len_a = 0, len_b = 0;
    char ch;
    do//读取两行多项式
    {
        scanf("%d%d%c", &factor_a[len_a].coe, &factor_a[len_a].power_a, &ch);
        len_a++;
    } while (ch != '\n');
    do
    {
        scanf("%d%d%c", &factor_b[len_b].coe, &factor_b[len_b].power_a, &ch);
        len_b++;
    } while (ch != '\n');
    qsort(factor_a, len_a, sizeof(POLY), cmp);//给两行多项式排序
    qsort(factor_b, len_b, sizeof(POLY), cmp);
    int len_c = 0;
    for (int i=0; i < len_a; i++)//计算多项式并存到c中
    {
        for (int j=0; j < len_b; j++)
        {
            factor_c[len_c].coe = factor_a[i].coe * factor_b[j].coe;
            factor_c[len_c].power_a = factor_a[i].power_a + factor_b[j].power_a;
            len_c++;
        }
    }
    qsort(factor_c, len_c, sizeof(POLY), cmp);//给c排序
    for (int i = 0; i < len_c-1; i++)//合并同类项
    {
        if (factor_c[i].power_a == factor_c[i + 1].power_a && factor_c[i].power_a != -1)
        {
            factor_c[i + 1].coe += factor_c[i].coe;
            factor_c[i].coe = 0;
            factor_c[i].power_a = -1;//将加完后的指数设置为-1
        }
    }
    qsort(factor_c, len_c, sizeof(POLY), cmp);//给c排序
    for (int i = 0; i < len_c && factor_c[i].power_a >= 0; i++)//输出到指数为负数之前
        if (factor_c[i].coe != 0)
            printf("%d %d ", factor_c[i].coe, factor_c[i].power_a);
    return 0;
}
