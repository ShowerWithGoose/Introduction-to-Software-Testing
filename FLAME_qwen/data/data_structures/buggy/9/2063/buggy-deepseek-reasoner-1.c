#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct place{
    int x1,y1;
    int x2,y2;
    int connect;
    int count;
};
int compare(const void *a,const void *b) 
{
    struct place *placeA = (struct place *)a;
    struct place *placeB = (struct place *)b;
    if (placeA->x1!=placeB->x1) 
    {
        return placeA->x1-placeB->x1;
    } 
    else 
    {
        return placeA->y1-placeB->y1;
    }
}
int main()
{
    struct place p[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&p[i].x1,&p[i].y1,&p[i].x2,&p[i].y2);
        p[i].connect=0;
        p[i].count=0;
    }
    qsort(p, n, sizeof(struct place), compare);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(p[j].x1==p[i].x2&&p[j].y1==p[i].y2)
            {
                p[i].count++; // @@ [Error: This only increments by 1 for each direct successor, but it does not accumulate the total number of segments in the entire continuous line. The chain length should be computed by traversing all connected segments, not by counting immediate successors.]
            }
        }
    }
    int most=0;
    for(int i=0;i<n;i++)
    {
        if(p[i].count>p[most].count) // @@ [Error: p[i].count does not represent the total number of segments in the chain starting from p[i]; thus the selection of `most` is based on an incorrect metric.]
        {
            most=i;
        }
    }
    printf("%d %d %d",p[most].count,p[most].x1,p[most].y1); // @@ [Error: p[most].count is not the maximum number of segments in a continuous line (it is at most 1 for any chain with a successor). Additionally, p[most] may not be the starting point of the longest chain because the starting point has no predecessor, not necessarily the segment with highest count.]
    return 0;
}