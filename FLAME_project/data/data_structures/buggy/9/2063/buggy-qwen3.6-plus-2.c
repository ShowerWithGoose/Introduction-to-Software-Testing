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
                p[i].count++; // @@ The logic only counts immediate connections from segment i to j, but fails to propagate the chain. It treats each segment independently rather than building a continuous chain. Also, it doesn't mark segments as used, so a segment might be counted in multiple chains or the chain length calculation is incorrect because it doesn't follow the linked structure recursively/iteratively.
            }
        }
    }
    int most=0;
    for(int i=0;i<n;i++)
    {
        if(p[i].count>p[most].count)
        {
            most=i;
        }
    }
    printf("%d %d %d",p[most].count,p[most].x1,p[most].y1); // @@ The output prints p[most].count which is just the number of direct successors found in the previous loop, not the total length of the continuous chain. For the test case, segment 0 connects to segment 1, so count is 1. But the chain length is 2 segments. The problem asks for the number of segments in the continuous line.
    return 0;
}