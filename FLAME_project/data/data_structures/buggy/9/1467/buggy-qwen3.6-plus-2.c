#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    int x1[150],y1[150],x2[150],y2[150],n,flag[150],x01,y01,x02,y02,flag0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
    }
    for (int i=1;i<n;i++)
    {
        for (int j=1;j<n;j++) // @@ The inner loop condition should be j <= n - i or similar to ensure full sorting, but more critically, the bubble sort implementation is flawed because it doesn't reduce the range. However, the major logical error is in the chain construction below.
        {
            if (x1[j]>x1[j+1])
            {
                x01=x1[j+1];  y01=y1[j+1];  x02=x2[j+1];  y02=y2[j+1];
                x1[j+1]=x1[j];y1[j+1]=y1[j];x2[j+1]=x2[j];y2[j+1]=y2[j];
                x1[j]=x01;    y1[j]=y01;    x2[j]=x02;    y2[j]=y02;
            }
        }
    }
    
    /*for (int i=1;i<=n;i++)
    {
        printf("%d %d %d %d\n",x1[i],y1[i],x2[i],y2[i]);
    }*/
    
    for (int i=1;i<=n;i++)
    {
        flag[i]=1;
        x1[0]=x1[i];y1[0]=y1[i];x2[0]=x2[i];y2[0]=y2[i];
        for (int j=1;j<=n;j++) // @@ This logic attempts to build a chain by scanning all segments linearly. It fails because it doesn't ensure the segments are visited in the correct order to form a continuous chain, nor does it mark used segments. It simply updates the end point whenever it finds *any* segment starting at the current end point, which might skip intermediate segments or pick wrong branches if not sorted/processed correctly. Specifically, it assumes that scanning 1..n will find the next link in the chain, but if the next link is at index k and a later link is at index m, it might update to m's endpoint without including k, breaking the chain continuity or length count.
        {
            if (x2[0]==x1[j] && y2[0]==y1[j])
            {
                x2[0]=x2[j];y2[0]=y2[j];
                flag[i]++;
            }
        }
    }
    flag[0]=0;
    for (int i=1;i<=n;i++)
    {
        if (flag[0]<flag[i])
        {
            flag[0]=flag[i];
            if (flag[0]==flag[i]) // @@ This condition is inside the block where flag[0] has just been updated to flag[i], so it is always true. However, the problem states there is only one max. The real issue is that this prints every time a new max is found, but since it's updating flag[0], it might print multiple times if not careful, or print the wrong one if the logic above was flawed. But the primary error is the chain construction.
            {
                printf("%d %d %d\n",flag[i],x1[i],y1[i]);
            }
        } 
    }
    
    return 0;
}