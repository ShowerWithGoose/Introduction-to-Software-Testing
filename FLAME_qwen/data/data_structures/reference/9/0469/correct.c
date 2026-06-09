#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int ch[105][5];

struct hello
{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
} line[105],temp;

int main()
{
    int n;
    int i,j,k,m;
    int x,y;
    int mod=0;
    int max=0;
    int first=0;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
        scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    for(i=1; i<=n; i++)
    {
        mod=0;
        for(j=i+1; j<=n; j++)
        {
            if(line[j].x1<line[i].x1)
            {
                temp=line[j];
                line[j]=line[i];
                line[i]=temp;
                mod=1;
            }
        }
        if(mod==0)
            break;
    }
    for(i=1;i<=n;i++)
    {
        m=1;k=i;
        for(j=i+1;j<=n;j++)
        {
            if(line[j].x1==line[k].x2&&line[j].y1==line[k].y2)
            {
                m++;
                k=j;
            }
        }
        if(m>max)
        {
            max=m;
            x=line[i].x1;
            y=line[i].y1;
        }
    }
    printf("%d %d %d\n",max,x,y);
    return 0;
}

