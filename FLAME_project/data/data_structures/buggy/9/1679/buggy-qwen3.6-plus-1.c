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
    for(int i=0;i<n;i++) // @@ The sorting algorithm is incorrect. It attempts a bubble-sort-like structure but breaks prematurely and only compares adjacent indices in a way that doesn't guarantee global sorting. Specifically, the inner loop starts at i+1 but swaps with i, then breaks if no swap occurred immediately, which fails to sort the array properly by x1. This leads to incorrect chain formation because segments are not processed in increasing x-order.
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
            if(sign == 0)
            break;
        }
    }
    int len,now,max=0;
    int finalx,finaly;
    for(int i=0;i<n;i++)
    {
        len=1;
        now=i;
        for(int j=i+1;j<n;j++)
        {
            if(point[j].x1==point[now].x2&&point[j].y1==point[now].y2)
            {
                len++;
                now=j;
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