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
                a[i]=0; // @@ [The logic for marking/unmarking visited elements is inverted. It should be a[i]=1 to mark as used, but here it's set to 0, which means it remains unmarked. Also, the initial state of a[i] is 0 (unvisited), so setting it to 0 again does nothing, causing repeated use of the same number.]
                dfs(m+1);
                a[i]=1; // @@ [This unmarks the element after recursion, but since it was never properly marked (was set to 0 above), this leads to incorrect backtracking. The correct sequence should be: mark with a[i]=1 before recursion, then unmark with a[i]=0 after.]
            }
}
int main()
{
    scanf("%d",&n); 
    dfs(0);
}