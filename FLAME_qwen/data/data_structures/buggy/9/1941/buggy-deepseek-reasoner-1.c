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
    for (int i = 0; i < n-1; i++) // @@ Error: Should iterate over all segments (i < n) to consider single-segment chains. As written, the last segment is never used as a start, and if n==1 the loop body never executes leaving max=0 and p1,p2 uninitialized.
    {
        int qt = 0; // @@ Error: Counter should start at 1 to include the starting segment itself, or later comparison should use qt+1.
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
        if (max < qt) // @@ Error: Should compare max < qt+1 (since qt counts additional segments only). Also this comparison is inside the loop but should be done after the inner loop completes.
        {
            max = qt;
            p1 = k[a[i]].a1;
            p2 = k[a[i]].a2;
        }
    }
    printf("%d %d %d", max, p1, p2); // @@ Error: If max remained 0 (e.g., no chain of length >=2 or n==0), p1,p2 are uninitialized.
    return 0;
}