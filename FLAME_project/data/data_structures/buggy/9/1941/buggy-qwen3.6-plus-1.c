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
        int qt = 0; // @@ The variable 'qt' counts the number of *additional* segments connected to the starting segment. It is initialized to 0, meaning if a chain of length 2 is found (1 connection), qt becomes 1. However, the problem asks for the total number of segments in the continuous line.
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
            max = qt; // @@ 'max' stores the count of connections (additional segments), not the total segments. For a single segment, qt=0. For two connected segments, qt=1. The expected output for 2 segments is 2, but this code will output 1.
            p1 = k[a[i]].a1;
            p2 = k[a[i]].a2;
        }
    }
    printf("%d %d %d", max, p1, p2); // @@ Since 'max' is the number of additional segments (connections), it undercounts the total segments by 1. It should print max + 1. Also, if no connections are found (max remains 0), it should still print 1 segment.
    return 0;
}