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
                a[i]=0; // @@ [The array 'a' is used to track which numbers are used, but here it's set to 0 (unused) right after using 'i', which should mark it as used (1). This causes the same number to be reused in the same permutation.]
                dfs(m+1);
                a[i]=1; // @@ [Backtracking step incorrectly sets a[i] to 1 (used) instead of resetting it to 0 (unused). This prevents correct reuse of numbers in other branches.]
            }
}
int main()
{
    scanf("%d",&n); 
    dfs(0);
}