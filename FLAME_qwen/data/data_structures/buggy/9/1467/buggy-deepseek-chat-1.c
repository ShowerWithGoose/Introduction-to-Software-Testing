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
        for (int j=1;j<n;j++)
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
        x1[0]=x1[i];y1[0]=y1[i];x2[0]=x2[i];y2[0]=y2[i]; // @@ Error: This overwrites the first element of the arrays (index 0) which is used as a temporary variable, but the arrays are 1-indexed and index 0 is not used for input data. However, the logic incorrectly modifies x1[0], y1[0], etc. which are not part of the original data, and the subsequent loop uses x2[0] and y2[0] to compare with other segments, but this approach fails to correctly chain segments because it only checks one connection per iteration and does not properly update the chain.
        for (int j=1;j<=n;j++)
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
            if (flag[0]==flag[i]) // @@ Error: This condition is always true because flag[0] was just set to flag[i], so the printf will execute for every i where flag[i] is greater than the previous maximum, not just the final maximum. This will print multiple lines instead of just the longest chain's starting point.
            {
                printf("%d %d %d\n",flag[i],x1[i],y1[i]);
            }
        } 
    }
    
    return 0;
}