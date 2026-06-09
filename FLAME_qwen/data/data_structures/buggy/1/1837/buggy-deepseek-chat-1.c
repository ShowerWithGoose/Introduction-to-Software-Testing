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
                a[i]=0; // @@ Error: Should set a[i]=1 to mark as used, not 0. The array a is used as a visited flag where 1 means used, but here it incorrectly sets to 0, causing infinite recursion or incorrect permutations.
                dfs(m+1);
                a[i]=1; // @@ Error: Should set a[i]=0 to unmark after recursion, but here it sets to 1, which is inconsistent with the marking logic.
            }
}
int main()
{
    scanf("%d",&n); 
    dfs(0);
}