#include <stdio.h>
#include <string.h>
#include <ctype.h>
struct point
{
    int x1,y1;
    int x2,y2;
    int sum;
}point[200],temp;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&point[i].x1,&point[i].y1,&point[i].x2,&point[i].y2);
    }
    for(int i=0;i<n;i++)
    {
        int sign = 0;
        for(int j=i+1;j<n;j++)
        {
            if(point[j].x1<point[i].x1)
            {
                temp=point[j];
                point[j]=point[i];
                point[i]=temp;
                sign = 1;
            }
            if(sign == 0) // @@ This break causes the sorting to only check the immediate next element, so the array is not properly sorted by x1. The loop should continue to check all j without breaking.
            break;
        }
    }
    int len,now,max=0;
    int finalx,finaly;
    for(int i=0;i<n;i++)
    {
        len=1;
        now=i;
        for(int j=i+1;j<n;j++) // @@ The assumption that the next segment in the chain is always at a higher index in the sorted array is incorrect. The chain may involve segments that are not adjacent in the array order, even after sorting. Moreover, the algorithm should search all remaining segments (including those before j) after updating `now`.
        {
            if(point[j].x1==point[now].x2&&point[j].y1==point[now].y2)
            {
                len++;
                now=j; // @@ After updating `now`, the search should restart from the beginning (index 0 or at least from the start of the inner loop) to find the next connecting segment, because a connecting segment may have an index smaller than the current j.
            }
        }
        if(len>max)
        {
            max=len;
            finalx=point[i].x1;
            finaly=point[i].y1;
        }
    }
    printf("%d %d %d\n",max,finalx,finaly);
}