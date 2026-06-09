#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    int a1;
    int a2;
    int b1;
    int b2;
}line;
line k[100];
int cmp(const void* x, const void* y)
{
    int a = *(int*)x;
    int b = *(int*)y;
    return k[a].a1 - k[b].a1;
}
int main()
{
    int n, a[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &k[i].a1, &k[i].a2, &k[i].b1, &k[i].b2);
        a[i] = i;
    }
    qsort(a, n, sizeof(int), cmp);
    int max = 0, p1, p2; // @@ max should be initialized to 1 to correctly handle cases with a single segment, and p1, p2 should be initialized to prevent undefined behavior if the loop does not execute.
    for (int i = 0; i < n-1; i++) // @@ The loop bound should be i < n to ensure all segments are considered as potential starting points, particularly when n=1.
    {
        int qt = 0; // @@ qt should be initialized to 1 because the count of segments in a continuous line must include the starting segment itself.
        int s = i;
        for (int j = s+1; j < n; j++)
        {
            if (k[a[s]].b1 > k[a[j]].a1)
                break;
            if (k[a[s]].b1 == k[a[j]].a1)
            {
                if (k[a[s]].b2 == k[a[j]].a2)
                {
                    qt++;
                    s = j;
                }
            }
        }
        if (max < qt)
        {
            max = qt;
            p1 = k[a[i]].a1;
            p2 = k[a[i]].a2;
        }
    }
    printf("%d %d %d", max, p1, p2);
    return 0;
}