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
    for (int i = 1; i < n; i++) // @@ [The loop starts from i=1, skipping the first segment as a potential starting point of the longest chain. This causes incorrect results when the longest chain starts at index 0.]
    {
        int current = 1;
        int currentX = lines[i].x2; // @@ [This initializes the chain from the end of the current segment (i), but then tries to extend forward by matching lines[j].x1 with currentX. However, the logic incorrectly assumes that the chain grows only in increasing index order after sorting by x1, which may skip valid connections that appear earlier in the array due to shared endpoints not aligned with x1 ordering.]
        int currentY = lines[i].y2;
        for (int j = i; j < n; j++) // @@ [The inner loop only checks segments from index i onward, but a valid continuation of the chain might exist before index i in the sorted array if its x1 matches currentX and y1 matches currentY. Sorting by x1 does not guarantee that all possible connected segments appear after the current one.]
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
    printf("%d %d %d\n", max, lines[start].x1, lines[start].y1); // @@ [Because the algorithm fails to consider chains starting at index 0 and may miss valid connections due to directional search limitations, the reported start point and max count can be incorrect.]
    return 0;
}