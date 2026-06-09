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
        for (int j=1;j<n;j++) // @@ The inner loop condition should be j <= n - i to correctly implement Bubble Sort, otherwise the largest elements might not bubble up correctly in all passes, although strictly speaking for correctness of sorting here j<n often works if implemented as standard bubble sort but standard is j < n-i+1 or similar. However, the critical error is below.
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
    int max_idx = 1; // @@ Initialize max_idx to track the index of the segment with the maximum chain length
    for (int i=1;i<=n;i++)
    {
        if (flag[0]<flag[i])
        {
            flag[0]=flag[i];
            max_idx = i; // @@ Update max_idx when a new maximum is found
        } 
    }
    printf("%d %d %d\n", flag[0], x1[max_idx], y1[max_idx]); // @@ Output the result based on the tracked max_idx instead of printing inside the loop which causes multiple outputs or wrong logic
    
    return 0;
}