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
                a[i]=0; // @@ Error: Should set a[i]=1 to mark as used, not 0. The array a is used as a visited flag where 0 means unused and 1 means used. Setting to 0 here incorrectly marks the number as unused.
                dfs(m+1);
                a[i]=1; // @@ Error: Should set a[i]=0 to unmark after recursion. Setting to 1 incorrectly marks the number as used when it should be freed.
            }
}
int main()
{
    scanf("%d",&n); 
    dfs(0);
}