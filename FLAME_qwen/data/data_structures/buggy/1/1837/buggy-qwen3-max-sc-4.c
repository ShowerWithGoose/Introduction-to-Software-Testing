#include<stdio.h>
int n;
int a[10];
int b[10];
void dfs(int m)//深度搜索n元排列
{
    if(m>=n)
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
                a[i]=0; // @@ [The logic is inverted: 'a[i]' should be marked as used (1), not unused (0). This causes incorrect backtracking and reuse of the same number multiple times.]
                dfs(m+1);
                a[i]=1; // @@ [This line attempts to unmark, but since it was set to 0 above, setting to 1 here actually marks it as used after returning, which is backwards. The correct sequence is: mark as used (1) before recursion, then unmark (0) after.]
            }
}
int main()
{
    scanf("%d",&n); 
    dfs(0);
}