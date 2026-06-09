#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x1, y1, x2, y2;
    int isVisited;
} Line;

int cmp(const void *a, const void *b)
{
    return ((Line *)a)->x1 - ((Line *)b)->x1;
}

int main()
{
    int n;
    scanf("%d", &n);
    Line lines[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &lines[i].x1, &lines[i].y1, &lines[i].x2, &lines[i].y2);
        lines[i].isVisited = 0;
    }
    qsort(lines, n, sizeof(Line), cmp);
    int max = 1, start = 0;
    for (int i = 1; i < n; i++) // @@ [The loop starts at i=1, so the first segment (i=0) is never considered as a starting point for the longest chain. This can cause incorrect results when the longest chain starts at the first segment.]
    {
        int current = 1;
        int currentX = lines[i].x2;
        int currentY = lines[i].y2;
        for (int j = i; j < n; j++) // @@ [The inner loop starts from j=i, but it should start from j=0 or j=i+1 to check all unvisited segments that can extend the chain. Starting at j=i causes the same segment to be checked again unnecessarily and misses segments before index i that might connect. Also, marking segments as visited prevents them from being part of other chains, but the algorithm doesn't explore all possible starting points correctly due to this greedy marking.]
        {
            if (lines[j].x1 == currentX && lines[j].y1 == currentY && lines[j].isVisited == 0)
            {
                current++;
                lines[j].isVisited = 1;
                currentX = lines[j].x2;
                currentY = lines[j].y2;
            }
        }
        if (current > max)
        {
            max = current;
            start = i;
        }
    }
    printf("%d %d %d\n", max, lines[start].x1, lines[start].y1); // @@ [If the longest chain starts at index 0, 'start' remains 0 only if max was updated from a chain starting at 0, but since the outer loop starts at i=1, the chain starting at 0 is never evaluated, leading to wrong starting point output.]
    return 0;
}