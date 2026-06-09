#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{
    struct line
    {
        int num;
        int x1;
        int x2;
        int y1;
        int y2;
        int linked;
    };
    struct line lines[105];
    int n,i,j,k,max,maxn,n1,t,count,m;
    int linked[105][105];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        lines[i].num=i+1;
        scanf("%d %d %d %d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
    }
    k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j==i)
            {
                continue;
            }
            if(lines[i].x2==lines[j].x1&&lines[i].y2==lines[j].y1)
            {
                linked[k][0]=i;
                linked[k][1]=j;
                k++;
            }
        }
    }
    n1=k;
    max=2;
    maxn=0;
    loop1:for(i=0;i<n1;i++)
    {
        count=2;
        t=linked[i][1];
        jax:j=0;
        loop2:for(j=0;j<n1;j++)
        {
            if(i==j)
            {
                continue;
            }
            else if(linked[j][0]==t)
            {
                count++;
                t=linked[j][1];
                goto jax;
            }
            if(count>max)
            {
                max=count;
                maxn=linked[i][0];
            }
        }
    }
    printf("%d %d %d\n",max,lines[maxn].x1,lines[maxn].y1);
    return 0;
}



