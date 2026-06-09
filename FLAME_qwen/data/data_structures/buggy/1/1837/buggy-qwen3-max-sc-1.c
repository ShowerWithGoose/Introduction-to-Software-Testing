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
                a[i]=0; // @@ [This line incorrectly sets a[i] to 0, which marks the number as unused, but it should mark it as used (1). This causes incorrect backtracking and repeated use of the same number.]
                dfs(m+1);
                a[i]=1; // @@ [This line incorrectly sets a[i] back to 1 after recursion, but since it was set to 0 before recursion, it should be restored to 0. The logic of marking/unmarking is inverted.]
            }
}
int main()
{
    scanf("%d",&n); 
    dfs(0);
}