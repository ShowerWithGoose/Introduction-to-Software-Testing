#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX 10000
struct x
{
    int xishu;
    int mi;
};
int compare(const void *p1, const void *p2)
{
    struct x **pa = (struct x **)p1;
    struct x **pb = (struct x **)p2;
    if ((*pa)->mi < (*pb)->mi)
        return -1;
    else if ((*pa)->mi == (*pb)->mi)
        return 0;
    else
        return 1;
}
int main()
{
    struct x *xp[MAX];
    struct x x1[MAX], x2[MAX], x[MAX];
    int n1 = 0, n2 = 0, n = 0;
    while (scanf("%d %d", &(x1[n1].xishu), &(x1[n1].mi)) != EOF)
    {
        n1++;
        if (getchar() == '\n')
            break;
    }
    while (scanf("%d %d", &(x2[n2].xishu), &(x2[n2].mi)) != EOF)
    {
        n2++;
        if (getchar() == '\n')
            break;
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            x[n].xishu = x1[i].xishu * x2[j].xishu;
            x[n].mi = x1[i].mi + x2[j].mi;
            xp[n] = &x[n];
            n++;
        }
    }
    qsort(xp, n, sizeof(struct x *), compare);

    for (int i = n; i >=0 ; i--) // @@ Array index out of bounds: xp has valid indices from 0 to n-1. Accessing xp[n] causes undefined behavior/segmentation fault. Should be initialized to n-1.
    {
        int j = 1;

        while ((i-j>=0)&&(xp[i]->mi) == (xp[i - j]->mi))
        {
            xp[i]->xishu += xp[i - j]->xishu; // @@ Merging logic does not zero out xp[i-j]->xishu, leaving the data structure inconsistent and potentially causing duplicate outputs if the skipping logic fails.
            j++;
        }
        if (xp[i]->xishu != 0)
        {
            printf("%d %d ", xp[i]->xishu, xp[i]->mi);
        }

        i-=j-1; // @@ Incorrect index adjustment logic. Combined with the for-loop's decrement, it attempts to skip merged terms but relies on fragile arithmetic that can lead to incorrect iteration or missed terms.
    }
}