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
                a[i]=0; // @@ [Error: Should mark the number as used by setting a[i]=1. Currently it remains 0, allowing the same number to be picked again in deeper recursion levels.]
                dfs(m+1);
                a[i]=1; // @@ [Error: Should backtrack by marking the number as unused (a[i]=0). Setting it to 1 permanently marks it as used, preventing it from being used in other branches.]
            }
}
int main()
{
    scanf("%d",&n); 
    dfs(0);
}