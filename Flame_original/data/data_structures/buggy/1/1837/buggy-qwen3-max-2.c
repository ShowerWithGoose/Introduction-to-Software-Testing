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
                a[i]=0; // @@ [The logic for marking and unmarking visited elements is inverted. It should be a[i]=1 to mark as used, but here it's set to 0, which means it remains available, causing incorrect permutations and infinite recursion in logic. Also, the initial state of a[i] is 0 (unused), so setting it to 0 again does nothing.]
                dfs(m+1);
                a[i]=1; // @@ [This unmarks the element by setting it to 1, which is opposite of standard usage tracking. Normally, 1 means used, 0 means unused. Here, it's reversed, leading to wrong availability checks.]
            }
}
int main()
{
    scanf("%d",&n); 
    dfs(0);
}