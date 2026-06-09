#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
int a, b, numk1, numk2, i1, i2, cnt, k1[1005][2], k2[1005][2], ans[2000][2], i;
char c;
int comp(const void *p1, const void *p2);
void find();
int main()
{
    i = 0;
    do
    {
        scanf("%d%d%c", &a, &b, &c);
        k1[i][0] = a;
        k1[i++][1] = b;
    } while (c != '\n');
    numk1 = i;
    i = 0;
    do
    {
        scanf("%d%d%c", &a, &b, &c);
        k2[i][0] = a;
        k2[i++][1] = b;
    } while (c != '\n');
    numk2 = i;
    qsort(k1, numk1, 8, comp);
    qsort(k2, numk2, 8, comp);
    cnt = 0;
    for (i1 = 0; i1 < numk1; i1++)
    {
        for (i2 = 0; i2 < numk2; i2++)
        {
            find();
        }
    }
    qsort(ans, cnt, sizeof(ans[0]), comp);
    for (i = 0; i < cnt; i++)
    {
        printf("%d %d ", ans[i][0], ans[i][1]);
    }
    return 0;
}
int comp(const void *p1, const void *p2)
{
    int *m = (int *)p1;
    int *n = (int *)p2;
    return *(n + 1) - *(m + 1);
}
void find()
{
    int i = 0;
    for (i = 0; i < cnt; i++)
    {
        if (ans[i][1] == k1[i1][1] + k2[i2][1])
        {
            ans[i][0] += k1[i1][0] * k2[i2][0];
            return;
        }
    }
    ans[cnt][0] += k1[i1][0] * k2[i2][0];
    ans[cnt++][1] = k1[i1][1] + k2[i2][1];
    return;
}

