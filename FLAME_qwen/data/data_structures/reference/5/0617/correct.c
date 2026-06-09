#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <memory.h>
#define mian main
typedef long long ll;
typedef unsigned long long ull;
#define forsx(i, a, b) for (int i = (a); i < (b); ++i)
#define forjx(i, a, b) for (int i = (a); i > (b); --i)

#define ElementType int
#define __MAX__ 105
ElementType max(ElementType a, ElementType b)
{
    return a > b ? a : b;
}

ElementType min(ElementType a, ElementType b)
{
    return a < b ? a : b;
}
struct dx
{
    int x;
    int z;
} data1[1005], data2[1005], ans[1005];
typedef struct dx *pData;

int cmpfunc(const void *a, const void *b)
{
    pData aa = (pData)a;
    pData bb = (pData)b;
    return bb->z - aa->z;
}
int main(int argc, const char *argv[])
{
    char tmp = 0;
    int cnt1 = 0, cnt2 = 0, cntans = 0;
    do
    {
        scanf("%d%d%c", &data1[cnt1].x, &data1[cnt1].z, &tmp);
        ++cnt1;
    } while (tmp != '\n');
    tmp = 0;
    do
    {
        scanf("%d%d%c", &data2[cnt2].x, &data2[cnt2].z, &tmp);
        ++cnt2;
    } while (tmp != '\n');
    qsort(data1, cnt1, sizeof(data1[0]), cmpfunc);
    qsort(data2, cnt2, sizeof(data2[0]), cmpfunc);
    for (int i = 0; i < cnt1; ++i)
    {
        for (int j = 0; j < cnt2; ++j)
        {
            ans[cntans].x = data1[i].x * data2[j].x;
            ans[cntans].z = data1[i].z + data2[j].z;
            cntans++;
        }
    }
    qsort(ans, cntans, sizeof(ans[0]), cmpfunc);
    int cntans_m = cntans;
    for (int i = 0; i < cntans_m - 1; ++i)
    {
        if (ans[i].z == ans[i + 1].z)
        {
            ans[i + 1].x += ans[i].x;
            ans[i].x = -1;
            ans[i].z = -1;
            cntans--;
        }
    }
    qsort(ans, cntans_m, sizeof(ans[0]), cmpfunc);
    for (int i = 0; i < cntans; ++i)
    {
        printf("%d %d ", ans[i].x, ans[i].z);
    }
    return 0;
}
