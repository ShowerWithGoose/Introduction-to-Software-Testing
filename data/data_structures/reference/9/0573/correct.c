#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

struct list
{
    int x1;
    int y1;
    int x2;
    int y2;
};

void sort(struct list lin[],int n)
{
    struct list ti;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            int z1=lin[i].x1;
            int z2=lin[j].x1;
            if(z1<z2)
            {
                ti=lin[i];
                lin[i]=lin[j];
                lin[j]=ti;
            }
        }
    }
}

int main()
{
    struct list line[105];
    int n,a,len=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }
    sort(line,n);
    printf("\n\n");
    //for(int i=0;i<n;i++)
    //{
     //   printf("%d %d %d %d\n",line[i].x1,line[i].y1,line[i].x2,line[i].y2);
    //}
    for(int i=0;i<n;i++)
    {
        int len1,x0,y0;
        x0=line[i].x2,y0=line[i].y2,len1=1;
        for(int j=i+1;j<n;j++)
        {
            if(line[j].x1==x0 && line[j].y1==y0)
            {
                len1+=1;
                x0=line[j].x2,y0=line[j].y2;
            }
        }
        if(len1>len)
        {
            a=i;len=len1;
        }
    }
    printf("%d %d %d",len,line[a].x1,line[a].y1);
    return 0;
}

