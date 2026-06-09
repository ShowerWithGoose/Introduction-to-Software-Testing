#include<stdio.h>
int n;
int a[10]; // @@ Array size is too small. Indices 1 to N are used, so when N=10, accessing a[10] is out of bounds. Size should be at least 11.
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
                a[i]=0; // @@ Logic error: should be a[i]=1 to mark the number as visited before recursion. Setting to 0 leaves it unvisited, causing infinite recursion.
                dfs(m+1);
                a[i]=1; // @@ Logic error: should be a[i]=0 to backtrack and restore the unvisited state. Setting to 1 incorrectly keeps it marked as visited.
            }
}
int main()
{
    scanf("%d",&n); 
    dfs(0);
}