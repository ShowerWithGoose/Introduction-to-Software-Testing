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
                p[i].count++; // @@ [This only counts immediate next segment, but does not build a chain. The 'count' field is being used to store the number of direct successors, not the total length of the continuous line starting at this segment. This leads to incorrect maximum length calculation.]
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
    printf("%d %d %d",p[most].count,p[most].x1,p[most].y1); // @@ [The output prints p[most].count, which is the number of direct connections from that segment, not the total number of segments in the continuous line. The problem requires the total number of segments in the longest continuous line, which may involve chaining multiple segments together.]
    return 0;
}