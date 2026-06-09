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
    for (int i = 1; i < n; i++) // @@ [The loop starts at i=1, so the first segment (i=0) is never considered as a starting point for the longest chain. This can cause incorrect results when the longest continuous line starts with the first segment after sorting.]
    {
        int current = 1;
        int currentX = lines[i].x2;
        int currentY = lines[i].y2;
        for (int j = i; j < n; j++) // @@ [The inner loop starts from j=i, but it should start from j=0 to consider all segments that might connect after the current one. By only checking from j=i onward, it misses segments that appear earlier in the array (but have larger x1 due to sorting) that could extend the chain. Also, the algorithm incorrectly assumes that connectivity only goes forward in the sorted array, which is not guaranteed because a segment later in the array might connect to one earlier if their coordinates match.]
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
    printf("%d %d %d\n", max, lines[start].x1, lines[start].y1); // @@ [If the longest chain starts at index 0, 'start' remains 0 due to initialization, but the loop never evaluates i=0, so 'max' might be wrong. Additionally, marking segments as visited during traversal prevents them from being used in other chains, but the problem does not state that segments can't be part of multiple potential chains during search—however, since only one maximal chain exists per constraints, this may be acceptable if the traversal were correct. The core issue is the incomplete search space due to loop bounds and directionality assumption.]
    return 0;
}