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
            if(sign == 0) // @@ This break exits the inner loop prematurely, preventing a full sort. Should only break after checking all j.
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
                now=j; // @@ Greedy update – picks the first matching segment without exploring other possibilities, potentially missing a longer chain.
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