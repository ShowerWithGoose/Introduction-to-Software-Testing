#include<stdio.h>
int n;
int re[15];
int tag[15];


void dfs(int x)
{
    int i,j;
    if(x>n)
    {
        for(j=1;j<=n;j++)
        printf("%d ",re[j]);
        printf("\n");
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(tag[i]==0)
        {
            re[x]=i;
            tag[i]=1;
            dfs(x+1);
            tag[i]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    dfs(1);
}
