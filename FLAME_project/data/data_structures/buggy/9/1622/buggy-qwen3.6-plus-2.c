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
    int max = 1, start = 0; // @@ The initialization of max to 1 and start to 0 assumes the first segment is part of the longest chain or handles single segments correctly, but the logic below fails to update 'start' correctly for the beginning of a chain if the chain starts at index 0 and is extended. More critically, the inner loop logic is flawed.
    for (int i = 0; i < n; i++) // @@ The outer loop should start from 0 to consider chains starting at the very first segment. Starting from 1 ignores potential chains starting at index 0.
    {
        if (lines[i].isVisited == 1) continue; // @@ We should skip segments that are already part of another chain to avoid double counting or incorrect chain formation, although the problem states unique max chain. More importantly, we need to reset current chain tracking for each new potential start.
        int current = 1;
        int currentX = lines[i].x2;
        int currentY = lines[i].y2;
        lines[i].isVisited = 1; // @@ Mark the starting segment as visited
        int tempStart = i; // @@ Keep track of the starting index of the current chain
        for (int j = i + 1; j < n; j++) // @@ Start searching from the next segment. Since sorted by x1, any connecting segment must have x1 >= current x1. Specifically, it must match currentX/currentY.
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
            start = tempStart; // @@ Update start to the beginning of the current longest chain
        }
    }
    printf("%d %d %d\n", max, lines[start].x1, lines[start].y1);
    return 0;
}