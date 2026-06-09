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
            if (k[a[s]].b1 > k[a[j]].a1) // @@ [Error: Should compare b1 with a1, but the struct field mapping is incorrect. The struct stores a1,a2,b1,b2 but the problem expects x1,y1,x2,y2. Here a1 is x1, a2 is y1, b1 is x2, b2 is y2. So to check if segment j's start (x1) equals segment s's end (x2), should compare k[a[s]].b1 (x2) with k[a[j]].a1 (x1). The condition uses > which is correct for break, but the logic for connecting is flawed.]
                break;
            if (k[a[s]].b1 == k[a[j]].a1) // @@ [Error: Same field mapping issue. Should compare k[a[s]].b1 (x2) with k[a[j]].a1 (x1) to check if they share an endpoint. However, the y-coordinate check below uses b2 and a2, which are y2 and y1 respectively, but the condition should be k[a[s]].b2 (y2) == k[a[j]].a2 (y1). The current code uses b2 and a2, which is correct if a2 is y1 and b2 is y2, but the struct definition is confusing. The main error is that the algorithm only checks consecutive segments after sorting by a1, but it does not properly merge segments; it only counts qt and updates s, but does not update the end point of the current chain, so it fails to connect more than two segments.]
            {
                if (k[a[s]].b2 == k[a[j]].a2) // @@ [Error: Should compare y2 (b2) with y1 (a2). This is correct if a2 is y1 and b2 is y2, but the logic is incomplete because after connecting, the end point of the chain should be updated to the new segment's end, but s is updated to j, which works only if the next segment directly follows. However, the algorithm does not handle cases where multiple segments can be connected in a chain because it only checks j from s+1 and breaks if b1 > a1, but it does not reset the search after updating s, so it may miss connections.]
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