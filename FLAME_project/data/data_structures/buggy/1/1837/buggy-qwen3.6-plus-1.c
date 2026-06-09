#include<stdio.h>
int n;
int a[10];
int b[10];
void dfs(int m)//深度搜索n元排列
{
    if(m>=n) // @@ The base case condition is incorrect. It should be `m == n` to ensure exactly N elements are placed. Using `>=` might work logically if controlled, but the main issue is below. However, looking at the logic: if m==n, we print. But let's look at the recursion.
    {
        for(int i=0;i<n;i++)
            printf("%d ",b[i]);
        printf("\n");
    }
    else
        for(int i=1;i<=n;i++)
            if(!a[i])
            {
                b[m]=i;
                a[i]=0; // @@ Error: The array `a` is used to mark visited numbers. It should be set to 1 (or non-zero) to mark `i` as used. Here it is set to 0, which means it remains "unused" or resets it incorrectly if it was already 0. Since `a` is global, it initializes to 0. Setting `a[i]=0` here does nothing to mark it as used. It should be `a[i]=1`.
                dfs(m+1);
                a[i]=1; // @@ Error: Backtracking step. If we marked it as 1 in the previous step, we should reset it to 0 here to allow `i` to be used in other branches. Here it is set to 1, which is the opposite of what is needed for backtracking if the forward step was correct. Given the forward step set it to 0, this sets it to 1. This logic is completely swapped.
            }
}
int main()
{
    scanf("%d",&n); 
    dfs(0);
}