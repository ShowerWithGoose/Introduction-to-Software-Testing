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
    for (int i = 1; i < n; i++) // @@ [The loop starts at i=1, skipping the first segment as a potential starting point of the longest chain. The longest continuous line might start at index 0, so this misses valid chains starting from the first segment.]
    {
        int current = 1;
        int currentX = lines[i].x2; // @@ [This initializes the chain from the end of the current segment (lines[i]), but the chain should start from the beginning of lines[i] and extend forward. Also, it incorrectly assumes lines[i] is already part of a chain without checking if it can be extended backward.]
        int currentY = lines[i].y2;
        for (int j = i; j < n; j++) // @@ [This inner loop only checks segments from index i onward, but after sorting by x1, a matching next segment could appear before i if not all segments are processed in order of connectivity. However, more critically, the logic does not correctly simulate building chains because it marks segments as visited during traversal but doesn't reset or consider alternative paths.]
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
    printf("%d %d %d\n", max, lines[start].x1, lines[start].y1); // @@ [If the longest chain starts at index 0, 'start' remains 0 due to initialization, but the loop never evaluates i=0, so if the actual longest chain starts at 0 and has length >1, it may not be captured correctly because the inner loop logic is flawed and the outer loop skips i=0. Additionally, the visited marking prevents reuse but the algorithm doesn't explore all possible starting points properly.]
    return 0;
}