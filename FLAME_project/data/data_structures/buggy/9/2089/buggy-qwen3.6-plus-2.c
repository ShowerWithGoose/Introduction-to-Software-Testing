#include<stdio.h>
#include <string.h>
int x1[105];
int x2[105];
int y11[105];
int y2[105];
int n;
int sum=1; // @@ The global variable 'sum' is not reset to 1 before each new chain calculation in the loop, and its usage in recursion combined with global state leads to incorrect counting. It should be local or properly managed.
int sumji[105];
int panduan(int a,int b)
{
    for(int k=0;k<n;k++)
    {
        if((x1[k]==a&&y11[k]==b))
        {
            sum++; // @@ Incrementing a global 'sum' inside a recursive function without proper backtracking or resetting causes the count to accumulate incorrectly across different branches or calls.
            panduan(x2[k],y2[k]); // @@ The return value of the recursive call is ignored, and the function continues to check other segments even after finding a match, which violates the constraint that no three segments share an endpoint (implying a unique path) but also logically fails to stop or handle the chain correctly. It should likely break or return immediately.
            return 1;
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
    }
    int xji=0,yji=0,sumji=1;
    if(n==1)
    {
        printf("1 %d %d\n",x1[0],y11[0]);

    }else 
    {
            for(int j=0;j<n;j++)
     {
         sum = 1; // @@ Missing reset of 'sum' to 1 before calling panduan for each starting segment. Without this, 'sum' retains values from previous iterations.
         if(panduan(x2[j],y2[j])>0)
        {
            if(sum>sumji)
            {
                sumji=sum;
                xji=x1[j];
                yji=y11[j];
                sum=1; // @@ This reset happens after the check, but since 'sum' is global and modified by recursion, it might not be 1 here if recursion didn't happen or failed. However, the critical error is the lack of reset *before* the call.
            }
            

        }
     }
        printf("%d %d %d\n",sumji,xji,yji);
    }

}