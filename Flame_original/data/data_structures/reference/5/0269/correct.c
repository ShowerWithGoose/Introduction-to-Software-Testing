#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct node
{
    int xishu;
    int zhishu;
} x[105], y[105], z[105];
int cmp(const void *p1, const void *p2)
{
    struct node *a = (struct node *)p1;
    struct node *b = (struct node *)p2;
    return b->zhishu - a->zhishu;
}
int main()
{
    char c;
    int i = 0, j = 0, k = 0, l1, l2;
    do
    {
        scanf("%d%d%c", &x[i].xishu, &x[i].zhishu, &c);
        i++;
    } while (c != '\n');
    l1 = i;
    do
    {
        scanf("%d%d%c", &y[j].xishu, &y[j].zhishu, &c);
        j++;
    } while (c != '\n');
    l2 = j;
    for (i = 0; i < l1; i++)
    {
        for (j = 0; j < l2; j++)
        {
            z[k].xishu = x[i].xishu * y[j].xishu;
            z[k].zhishu = x[i].zhishu + y[j].zhishu;
            k++;
        }
    }
    qsort(z, k, sizeof(z[0]), cmp);
    for (i = 0; i < k; i++)
    {
        if (z[i].zhishu == z[i - 1].zhishu)
        {
            z[i].xishu += z[i - 1].xishu;
            z[i - 1].xishu = 0;
        }
    }
    for (i = 0; i < k; i++)
    {
        if (z[i].xishu)
            printf("%d %d ", z[i].xishu, z[i].zhishu);
    }
    return 0;
}


