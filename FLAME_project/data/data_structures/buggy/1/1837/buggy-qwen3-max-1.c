#include<stdio.h>
int n;
int a[10];
int b[10];
void dfs(int m)//深度搜索n元排列
{
    if(m>=n) // @@ [The condition should be m == n, not m >= n. Since m starts at 0 and goes up to n-1 for n elements, when m == n, we have filled all positions. Using >= may cause early termination or extra empty outputs in some cases, but more critically combined with other bugs it leads to incorrect behavior.]
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
                a[i]=0; // @@ [This line sets a[i] to 0, which means marking it as unused, but it should mark it as used (1). This causes the same number to be reused in the same permutation, leading to duplicates like "1 1".]
                dfs(m+1);
                a[i]=1; // @@ [Because a[i] was incorrectly set to 0 above, restoring it to 1 here is backwards. It should be set to 1 before recursion and reset to 0 after.]
            }
}
int main()
{
    scanf("%d",&n); 
    dfs(0);
}