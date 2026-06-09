#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int n;

struct xian
{
    int x1;
    int y1;
    int x2;
    int y2;
}line[105],biao;

void read()
{
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }
}

void sort()
{
for(int i=0;i<n;i++)
{
    for(int j=i;j<n;j++)
    {
        if(line[i].x1>line[j].x1)
        {
            biao=line[i];
            line[i]=line[j];
            line[j]=biao;
        }
        else if(line[i].x1==line[j].x1&&line[i].y1>line[j].y1)
        {
            biao=line[i];
            line[i]=line[j];
            line[j]=biao;
        }
    }
}
}
int main()
{
scanf("%d",&n);
read();
sort();
int count[n];
int g,max,maxf;
for(int s=0;s<n;s++)
    {
        count[s]=0;
    }
    for(int i=0;i<n;i++)
    {
        g=i;
        for(int j=i+1;j<n;j++)
        {
            if(line[g].x2==line[j].x1&&line[g].y2==line[j].y1)
            {
                g=j;
                count[i]++;
            }
        }
    }
    max=count[0],maxf=0;
    for(int p=1;p<n;p++)
    {
        if(max<=count[p])
        {
            max=count[p];
            maxf=p;
        }
    }
    printf("%d %d %d",max+1,line[maxf].x1,line[maxf].y1);
  return 0;
}

