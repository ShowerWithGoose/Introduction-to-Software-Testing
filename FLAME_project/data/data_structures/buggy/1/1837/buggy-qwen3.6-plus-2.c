#include<stdio.h>
int n;
int a[10];
int b[10];
void dfs(int m)//深度搜索n元排列
{
    if(m>=n) // @@ The base case condition is incorrect. It should be `m == n` to ensure exactly N elements are placed. Using `m >= n` might cause issues if logic elsewhere allows m to exceed n, but the primary logical error causing the wrong output is below.
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
                a[i]=0; // @@ Error: The state should be marked as used (1) before recursing, not 0. Since `a` is global and likely initialized to 0, setting it to 0 keeps it marked as unused, allowing the same number to be picked again in deeper recursive calls or sibling branches incorrectly. It should be `a[i] = 1`.
                dfs(m+1);
                a[i]=1; // @@ Error: The backtracking step should reset the state to unused (0), not 1. It should be `a[i] = 0`.
            }
}
int main()
{
    scanf("%d",&n); 
    dfs(0);
}