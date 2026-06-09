#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int n,maxlen=0,i,i,j,k,len;
struct xy
{
    int x1;
    int y1;
    int x2;
    int y2;
    int flag;
};
int search(struct xy array[],int now,int next,int lenght)
{
    if(next==n)
        return lenght;
    else if(array[now].x2==array[next].x1&&array[now].y2==array[next].y1&&array[next].flag==0)
    {
        array[next].flag=1;
        return search(array,next,0,lenght+1);
    }
    else
    {
        return search(array,now,next+1,lenght);
    }
}
int main()
{
    scanf("%d",&n);
    struct xy point[105];
    for(i=0; i<n; i++)
        scanf("%d%d%d%d",&point[i].x1,&point[i].y1,&point[i].x2,&point[i].y2);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            point[j].flag=0;
        point[i].flag=1;
        len = search(point,i,0,1);
        if(len > maxlen)
        {
            maxlen = len;
            i = i;
        }
    }
    printf("%d %d %d",maxlen,point[i].x1,point[i].y1);
    return 0;
}

