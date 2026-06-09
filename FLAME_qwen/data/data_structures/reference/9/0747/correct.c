#include<stdio.h>
struct situation
{
    int x1;
    int y1;
    int x2;
    int y2;
}point[110],temp,zero={-1,-1,-1,-1};
int main()
{
    int i,n,j,max=0;
    int len[110]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d %d %d",&point[i].x1,&point[i].y1,&point[i].x2,&point[i].y2);
    for(i=0;i<n-1;i++)
    {
        for(j=i;j<n-1;j++)
        {
            if(point[i].x1>point[j+1].x1)
            {
                temp=point[i];
                point[i]=point[j+1];
                point[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(point[j].x1==point[i].x2&&point[j].y1==point[i].y2&&point[j].x1!=-1)
            {
                point[i].x2=point[j].x2;
                point[i].y2=point[j].y2;
                len[i]=len[i]+1;
                point[j]=zero;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(len[i]>len[max])
            max=i;
    }
    printf("%d %d %d",len[max]+1,point[max].x1,point[max].y1);
    return 0;
}

