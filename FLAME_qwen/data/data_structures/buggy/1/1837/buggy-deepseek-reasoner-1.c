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
                a[i]=0; // @@ 错误：标记使用应设为1，而非0，否则数字会被重复使用，导致排列错误及无限递归
                dfs(m+1);
                a[i]=1; // @@ 错误：回溯时应恢复为0（未使用），而非1，否则数字之后无法再次使用
            }
}
int main()
{
    scanf("%d",&n); 
    dfs(0);
}