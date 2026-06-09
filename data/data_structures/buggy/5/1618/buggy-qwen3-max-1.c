#include <stdio.h>
#include <stdlib.h>
typedef struct Shi_
{
    int dishu;
    int zhishu;
} Shi;
int cmp(const void *p1, const void *p2)
{
    Shi *s1 = (Shi *)p1;
    Shi *s2 = (Shi *)p2;
    return s2->zhishu - s1->zhishu;
}
int main()
{
    Shi shi1[1000];
    Shi shi2[1000];
    Shi shi3[2000];
    int i = 0, j = 0, k, r, l = 0, q;
    char op;
    while (scanf("%d %d%c", &shi1[i].dishu, &shi1[i].zhishu, &op) != EOF)
    {
        if (op != '\n')
        {
            i++;
        }
        else
        {
            break;
        }
    }
    while (scanf("%d %d%c", &shi2[j].dishu, &shi2[j].zhishu, &op) != EOF)
    {
        if (op != '\n')
        {
            j++;
        }
        else
        {
            break;
        }
    }
    qsort(shi1,i,sizeof(Shi),cmp);
    qsort(shi2,j,sizeof(Shi),cmp);
    for (k = 0; k <= i; k++) // @@ [Loop condition should be k < i, not k <= i. This causes out-of-bounds access to shi1[i], which is uninitialized.]
    {
        for (r = 0; r <= j; r++) // @@ [Loop condition should be r < j, not r <= j. This causes out-of-bounds access to shi2[j], which is uninitialized.]
        {
            shi3[l].dishu = shi1[k].dishu * shi2[r].dishu;
            shi3[l].zhishu = shi1[k].zhishu + shi2[r].zhishu;
            l++;
        }
    }
    qsort(shi3, l, sizeof(Shi), cmp);
    for (q = 0; q < l; q++)
    {
        if (shi3[q].zhishu == shi3[q + 1].zhishu) // @@ [Accesses shi3[q + 1] when q == l - 1, leading to out-of-bounds read. Should check q + 1 < l.]
        {
            shi3[q+1].dishu = shi3[q].dishu + shi3[q + 1].dishu;
            shi3[q].dishu = 0;
        }
    }
    for (q = 0; q < l; q++)
    {
        if (shi3[q].dishu != 0)
        {
            printf("%d %d ", shi3[q].dishu, shi3[q].zhishu);
        }
    }
    return 0;
}