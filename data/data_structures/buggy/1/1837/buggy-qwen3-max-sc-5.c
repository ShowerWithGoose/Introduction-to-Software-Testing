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
                a[i]=0; // @@ [This line incorrectly sets a[i] to 0, which means the number i is marked as unused even though it's being used in the current permutation. It should be set to 1 to mark it as used.]
                dfs(m+1);
                a[i]=1; // @@ [This line incorrectly sets a[i] back to 1 after recursion, but since it was wrongly set to 0 before, this restoration is also inverted. The correct logic is to set a[i]=1 before recursion and a[i]=0 after.]
            }
}
int main()
{
    scanf("%d",&n); 
    dfs(0);
}