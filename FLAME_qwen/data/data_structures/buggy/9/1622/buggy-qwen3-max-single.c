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
    for (int i = 1; i < n; i++)
    {
        int current = 1;
        int currentX = lines[i].x2;
        int currentY = lines[i].y2;
        for (int j = i; j < n; j++)
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
    printf("%d %d %d\n", max, lines[start].x1, lines[start].y1); // @@ [The algorithm fails to consider chains starting from unvisited segments before index i, and marking segments as visited prevents them from being part of longer chains that might start earlier. Also, the initial max assumes at least one segment, but doesn't correctly build chains from every possible starting point without interference from the isVisited flag.]
    return 0;
}