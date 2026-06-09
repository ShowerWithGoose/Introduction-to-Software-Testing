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
        scanf("%d%d%d%d", &k[i].a1, &k[i].a2, &k[i].b1, &k[i].b2); // @@ [The input order is wrong: it reads a1, a2, b1, b2 but should read a1, b1, a2, b2 to match the problem's endpoint format (x1 y1 x2 y2). This causes coordinates to be misassigned.]
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
            if (k[a[s]].b1 > k[a[j]].a1)
                break;
            if (k[a[s]].b1 == k[a[j]].a1)
            {
                if (k[a[s]].b2 == k[a[j]].a2) // @@ [This condition checks if endpoint (b1,b2) of current segment matches start point (a1,a2) of next, but due to earlier input error, b1/b2 and a1/a2 are swapped. Even if input were correct, this logic only counts additional segments beyond the first, so qt starts at 0 and misses counting the initial segment.]
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
            p2 = k[a[i]].a2; // @@ [Due to input misassignment, a2 is actually the y-coordinate of the first point, not the x-coordinate. Also, since qt doesn't include the starting segment, max will be 1 less than actual count. For 2 segments, qt=1, but output prints max=1 instead of 2.]
        }
    }
    printf("%d %d %d", max, p1, p2); // @@ [Because 'qt' counts only the number of connections (i.e., additional segments), not total segments, the output number is one less than expected. It should be qt+1. Also, due to coordinate misassignment from input error, the printed starting point may be incorrect even if count were fixed.]
    return 0;
}