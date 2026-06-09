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
                a[i]=0; // @@ [This line incorrectly sets a[i] to 0, which should mark the number as used. It should be set to 1 instead. Also, the initial state of a[i] is 0 (unused), so setting it to 0 again does nothing and causes infinite recursion or incorrect permutations.]
                dfs(m+1);
                a[i]=1; // @@ [This line tries to backtrack by setting a[i] back to 1, but since it was never set to 1 before the recursive call, this logic is inverted. The correct approach is to set a[i]=1 before recursion and a[i]=0 after.]
            }
}
int main()
{
    scanf("%d",&n); 
    dfs(0);
}