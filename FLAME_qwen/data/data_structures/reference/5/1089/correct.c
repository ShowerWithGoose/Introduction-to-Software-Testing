#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int exp;
    int coe;
} a[100000], b[100000], c[100000];
int cmp(const void *a, const void *b)
{
    struct node *c = (struct node *)a;
    struct node *d = (struct node *)b;
    return d->exp - c->exp;
}
int main()
{
    int I = 0, J = 0;
    char p = ' ';
    while (p != '\n')
    {
        scanf("%d%d%c", &a[I].coe, &a[I].exp, &p);
        I++;
    }
    p = ' ';
    while (p != '\n')
    {
        scanf("%d%d%c", &b[J].coe, &b[J].exp, &p);
        J++;
    }
    int i, j, k = 0;
    for (i = 0; i < I; i++)
    {
        for (j = 0; j < J; j++)
        {
            c[k].exp = a[i].exp + b[j].exp;
            c[k].coe = a[i].coe * b[j].coe;
            k++;
        }
    }
    qsort(c, k, sizeof(c[0]), cmp);
    for (int i = 0; i < k; i++)
    {
        if (c[i].exp == c[i + 1].exp && c[i].exp != 0)
        {
            c[i + 1].coe += c[i].coe;
            c[i].coe = 0;
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (c[i].coe != 0)
        {
            printf("%d %d ", c[i].coe, c[i].exp);
        }
    }
    return 0;
}


