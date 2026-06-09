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
                p[i].count++; // @@ The logic only counts direct connections from segment i to j, but fails to propagate the chain length. If segment A connects to B, and B connects to C, A's count should reflect the full chain length (or be calculated via DFS/DP). Currently, it only counts immediate neighbors. Furthermore, the final output uses p[most].count which is just the number of immediate successors, not the total segments in the continuous line. For the test case, segment 0 connects to segment 1. p[0].count becomes 1. p[1].count remains 0. The max count is 1. But the expected output is 2 segments. The count should represent the total number of segments in the chain starting at i.
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
    printf("%d %d %d",p[most].count,p[most].x1,p[most].y1); // @@ The output prints the count of immediate connections, not the total number of segments in the longest continuous line. It should print the total length of the chain. Also, if the chain length is calculated correctly, it should be count + 1 (including the starting segment).
    return 0;
}