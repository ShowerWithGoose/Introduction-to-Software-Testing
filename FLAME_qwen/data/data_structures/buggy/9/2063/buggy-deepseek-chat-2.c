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
                p[i].count++; // @@ [Error: This only counts segments that follow p[i] in sorted order, but the longest continuous line may require connecting segments in a chain, not just counting immediate successors. The algorithm does not actually build the chain or track the starting point correctly.]
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
    printf("%d %d %d",p[most].count,p[most].x1,p[most].y1); // @@ [Error: p[most].count only counts immediate successors, not the total number of segments in the continuous line. Also, the starting point should be the first segment of the longest chain, not necessarily the one with the most immediate successors.]
    return 0;
}