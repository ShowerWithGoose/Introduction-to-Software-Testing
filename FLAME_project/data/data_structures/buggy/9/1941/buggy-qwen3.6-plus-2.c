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
    int max = 0, p1, p2;
    for (int i = 0; i < n-1; i++)
    {
        int qt = 0; // @@ The variable 'qt' counts the number of *additional* segments connected to the starting segment. It is initialized to 0. However, the total number of segments in the continuous line should include the starting segment itself. So the count should be at least 1 if any connection is found, or we should initialize qt to 1 and count connections. Currently, if two segments connect, qt becomes 1, but the output expects 2.
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
    printf("%d %d %d", max, p1, p2); // @@ Since 'qt' only counts the extensions, 'max' holds the number of additional segments. The problem asks for the total number of segments. We need to print max + 1. Also, if no segments are connected, max remains 0, which is incorrect for a single segment case (should be 1). But given the constraint "maximum number of segments", and usually at least one segment exists. The primary error is that the count is off by 1.
    return 0;
}