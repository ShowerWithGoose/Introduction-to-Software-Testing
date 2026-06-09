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
    for (int i = 1; i < n; i++) // @@ [The loop starts at i=1, so the first segment (i=0) is never considered as a starting point for the longest chain, which may cause missing the actual longest continuous line if it starts at index 0.]
    {
        int current = 1;
        int currentX = lines[i].x2;
        int currentY = lines[i].y2;
        for (int j = i; j < n; j++) // @@ [This inner loop only checks segments from index i onward, but after sorting by x1, a connecting segment might appear before index i in the array, so valid connections could be missed. Also, marking segments as visited prevents them from being part of multiple chains, but the problem does not state that segments can't be reused—however, constraint #3 implies uniqueness, but the algorithm's greedy visitation may break valid longer chains.]
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
    printf("%d %d %d\n", max, lines[start].x1, lines[start].y1); // @@ [If the longest chain starts at index 0, 'start' remains 0 due to initialization, but the loop never evaluates i=0, so if the true longest chain starts at 0 and has length 1, it may still output correctly; however, if a longer chain starts at 0, it will be missed because the outer loop starts at i=1.]
    return 0;
}