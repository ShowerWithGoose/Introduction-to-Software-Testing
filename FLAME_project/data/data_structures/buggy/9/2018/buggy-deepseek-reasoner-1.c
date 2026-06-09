#include <stdio.h>
#include <stdlib.h>
struct message
{
    int sx,sy,ex,ey;
    int a;
}line[101];

int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&line[i].sx,&line[i].sy,&line[i].ex,&line[i].ey);
        line[i].a=-1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                continue;
            }
            if(line[i].ex==line[j].sx&&line[i].ey==line[j].sy) // @@ Only forward links are created; backward links are ignored, so the true start of the chain cannot be identified.
            {
                line[i].a=j;
                break;
            }
        }
    }
    int number=1; // @@ Should be reset inside the loop for each starting segment i; otherwise numbers accumulate across iterations.
    int b=0;
    int numbermax,sxmax,symax,middle;
    for(i=0;i<n;i++)
    {
        middle=i;
        while(line[middle].a!=-1)
        {
            number++; // @@ This increment accumulates across different i because number is not re‑initialized for each i.
            middle=line[middle].a;
        }
        if(b==0)
        {
            numbermax=number;
            sxmax=line[i].sx; // @@ line[i].sx is not guaranteed to be the true start of the chain; a segment may have a predecessor.
            symax=line[i].sy;
            b=1;
        }
        else if(b==1)
        {
            if(number>numbermax)
            {
                numbermax=number;
                sxmax=line[i].sx; // @@ Same issue: the start point is taken from the current segment, not the head of the chain.
                symax=line[i].sy;
            }
        }
    }
    printf("%d %d %d",numbermax,sxmax,symax);
    return 0;
}