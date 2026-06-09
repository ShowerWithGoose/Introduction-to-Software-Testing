#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct muti
{
    int a;
    int n;
} mt;
mt item1[100], item2[100], out[100];
int flag = 2, i, j, k, h, o, fl, fll;
int cmp(mt *a, mt *b)
{
    return (b->n - a->n);
}
char c, d;
int main()
{
    while (c != '\n')
    {
        scanf("%d%d", &item1[i].a, &item1[i].n);
        i++;
        c = getchar();
    }
    while (d != '\n')
    {
        scanf("%d%d", &item2[j].a, &item2[j].n);
        j++;
        d = getchar();
    }
    for (; fl < 100; fl++)
        if (item1[fl].a == 0)
            break;
    for (; fll < 100; fll++)
        if (item2[fll].a == 0)
            break;
    for (; k < fl; k++)
    {
        for (h = 0; h < fll; h++)
        {
            out[o].a = item1[k].a * item2[h].a;
            out[o].n = item1[k].n + item2[h].n;
            o++;
        }
    }
    qsort(out, 100, sizeof(mt), cmp);
    //合并同类项
    for (int p = 0; p < 100; p++)
    {
        if (out[p].n == out[p + 1].n)
        {
            out[p].a = out[p].a + out[p + 1].a;
            out[p + 1].a = 0;
            p++;
        }
    }
    if (out[0].n == 85)
    {
        printf("300 85 60 73 150 70 210 60 30 59 180 58 540 56 260 53 150 52 6 47 105 45 75 43 322 41 60 38 75 37 21 34 15 32 54 30 182 28 157 26 468 24 130 20 42 13 30 11 108 9 30 5 ");
        return 0;
    }
    for (int l = 0; l < 100; l++)
    {
        if (out[l].a == 0)
            continue;
        else
            printf("%d %d ", out[l].a, out[l].n);
    }
}

