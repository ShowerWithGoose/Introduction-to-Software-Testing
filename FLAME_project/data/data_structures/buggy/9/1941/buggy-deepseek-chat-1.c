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
        int qt = 0;
        int s = i;
        for (int j = s+1; j < n; j++)
        {
            if (k[a[s]].b1 > k[a[j]].a1) // @@ [Error: Should compare b1 with a1, but b1 is the y-coordinate of the second endpoint, not the x-coordinate. The x-coordinate of the second endpoint is stored in b1? Actually the struct uses a1,a2 for first endpoint (x,y) and b1,b2 for second endpoint (x,y). So b1 is the x-coordinate of the second endpoint. However, the condition should check if the second endpoint's x (b1) equals the next segment's first endpoint x (a1). The comparison is correct in logic but the break condition is wrong: it should break when b1 > a1, but the loop should continue to find matching segments. The main error is that qt is not incremented correctly for the first segment itself.]
                break;
            if (k[a[s]].b1 == k[a[j]].a1)
            {
                if (k[a[s]].b2 == k[a[j]].a2) // @@ [Error: Should compare y-coordinates: b2 (y of second endpoint) with a2 (y of first endpoint). This is correct, but the logic fails because qt starts at 0 and only increments when a match is found, but the first segment itself is not counted. Also, the loop does not handle multiple consecutive segments correctly because after a match, s is updated but the inner loop continues from j+1, which may skip potential matches.]
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