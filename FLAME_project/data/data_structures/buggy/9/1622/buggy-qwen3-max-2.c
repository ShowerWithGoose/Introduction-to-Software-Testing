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
    for (int i = 1; i < n; i++) // @@ [The loop starts from i=1, so the first segment (index 0) is never considered as a starting point of a chain, even if it leads to the longest continuous line.]
    {
        int current = 1;
        int currentX = lines[i].x2;
        int currentY = lines[i].y2;
        for (int j = i; j < n; j++) // @@ [This inner loop only checks segments from index i onward, but matching segments could appear before i due to sorting only by x1. Also, the algorithm does not correctly simulate chaining in both directions or properly track all possible continuations.]
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
    printf("%d %d %d\n", max, lines[start].x1, lines[start].y1); // @@ [Because the loop starts at i=1 and doesn't consider chains starting at index 0, and because visited flags prevent reuse but are applied inconsistently, the output may miss the correct starting point and count. In the test case, the chain starts at index 0, but it's never evaluated as a full chain.]
    return 0;
}