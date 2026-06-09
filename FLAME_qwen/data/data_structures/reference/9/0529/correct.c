#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
struct xian
{
    int x1;
    int y1;
    int x2;
    int y2;
    int duan;
};
int main()
{
    struct xian lines[105],zhong;
    int n,i,j,k,max=-1,x,y;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
    }
    for(i=0;i<n;i++)
    {
        lines[i].duan=1;
    }
    for(j=0;j<n;j++)
            for(k=j+1;k<n;k++)
        {
            if(lines[j].x1>lines[k].x1)
            {
                zhong=lines[j];
                lines[j]=lines[k];
                lines[k]=zhong;
            }
        }
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
    {
        if(lines[i].x2==lines[j].x1&&lines[i].y2==lines[j].y1)
        {
            lines[i].x2=lines[j].x2;
            lines[i].y2=lines[j].y2;
            lines[i].duan=lines[i].duan+lines[j].duan;
        }
    }
    for(i=0;i<n;i++)
    {
        if(max<lines[i].duan)
        {
            max=lines[i].duan;x=lines[i].x1;y=lines[i].y1;
        }
    }
    printf("%d %d %d",max,x,y);
return 0;
}

