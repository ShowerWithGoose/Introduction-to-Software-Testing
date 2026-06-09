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
                a[i]=0; // @@ [The logic for marking and unmarking visited elements is inverted. It should be a[i]=1 to mark as used, not 0.]
                dfs(m+1);
                a[i]=1; // @@ [This unmarks the element by setting it to 1, but since it was set to 0 above (which means unused), this causes incorrect backtracking. The correct sequence is: mark as used (1), recurse, then unmark (0).]
            }
}
int main()
{
    scanf("%d",&n); 
    dfs(0);
}