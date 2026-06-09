#include<stdio.h>
#include <string.h>
int x1[105];
int x2[105];
int y11[105];
int y2[105];
int n;
int sum=1; // @@ [Global sum should be 0 and reset before each chain; initializing to 1 leads to overcount and incorrect chain counting.]
int sumji[105];
int panduan(int a,int b)
{
    for(int k=0;k<n;k++)
    {
        if((x1[k]==a&&y11[k]==b))
        {
            sum++; // @@ [sum should be incremented only after finding a match, but due to global state and lack of reset, it accumulates incorrectly across calls.]
            panduan(x2[k],y2[k]);
            return 1; // @@ [Immediately returns after first match, not exploring other possible continuations that could lead to longer chain.]
        }
    }
    return -1;
}
int main()
{
    
    
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&x1[i],&y11[i],&x2[i],&y2[i]);
    } // @@ [Missing sorting of segments by x1 to ensure correct order of chaining and optimal path.]
    int xji=0,yji=0,sumji=1; // @@ [Local sumji shadows global array; initialized to 1 should be 0 to handle no chain case; also needs to be reset correctly.]
    if(n==1)
    {
        printf("1 %d %d\n",x1[0],y11[0]);

    }else 
    {
            for(int j=0;j<n;j++)
     {
         if(panduan(x2[j],y2[j])>0) // @@ [Calls panduan without resetting sum; sum may contain stale value from previous unsuccessful chains, causing inflated count.]
        {
            if(sum>sumji) // @@ [Uses global sum which may be incorrect; should compare using a local variable.]
            {
                sumji=sum;
                xji=x1[j];
                yji=y11[j];
                sum=1; // @@ [Reset sum to 1 only after successful update; should reset sum to 1 (or 0) before every call to panduan to ensure each chain is counted independently.]
            }
            

        }
     }
        printf("%d %d %d\n",sumji,xji,yji);
    }

}