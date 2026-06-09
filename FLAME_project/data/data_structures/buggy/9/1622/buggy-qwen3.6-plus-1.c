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
    int max = 1, start = 0; // @@ The initialization of 'start' to 0 assumes the first segment is part of the longest chain if no longer chain is found, but the loop starts from i=1. If the longest chain starts at index 0, it might not be correctly identified or updated if the logic inside the loop doesn't handle the case where the chain starting at 0 is the longest. More critically, the variable 'start' stores the index 'i' which is the *last* segment processed in the inner loop's perspective of starting a chain, but actually 'i' is just the current segment being checked as a potential start. Wait, looking at the logic: 'start = i' means the segment at index 'i' is considered the start of the chain. However, the chain is built by finding subsequent segments. The actual start of the continuous line is lines[i].x1, lines[i].y1. This part seems logically okay for tracking the start index IF the chain starting at i is the longest.
    for (int i = 1; i < n; i++) // @@ The loop starts from i=1, ignoring the possibility that the longest continuous line segment starts with the first segment (index 0) after sorting. The segment at index 0 could be the start of the longest chain. By skipping i=0, we miss checking chains that begin with the first segment in the sorted array.
    {
        int current = 1;
        int currentX = lines[i].x2;
        int currentY = lines[i].y2;
        for (int j = i; j < n; j++) // @@ The inner loop starts from j=i. It should start from j=i+1 because we are looking for the *next* segment that connects to the current end point. Starting from j=i will compare the segment with itself if the condition wasn't protected by isVisited, but more importantly, the connection logic implies finding a *subsequent* segment. Although lines[i] is not marked visited yet, comparing lines[i] with lines[i] (x1==x2? No, x1<x2 usually) might not match unless degenerate. But logically, we look for the next piece. Standard practice is j=i+1. However, the bigger issue is that this greedy approach inside the inner loop doesn't reset properly or explore all branches? No, the problem states "No three or more segments share a single endpoint" and "No two line segments intersect in the middle", implying a simple linked list structure. So a greedy walk is fine. But wait, if we start at i, we mark subsequent nodes as visited. This prevents them from being used as starts for other chains. This is correct for disjoint chains. BUT, the outer loop iterates through all i. If a segment was visited in a previous chain (started by a smaller i), it should not be used again. The check `lines[j].isVisited == 0` handles this.
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
    printf("%d %d %d\n", max, lines[start].x1, lines[start].y1);
    return 0;
}