#include <stdio.h>
int a[20];
int vis[20];
int ex[20];
int n,p;
void dfs(int ith)
{
	int i;
    if(ith==n)
    {
        for(i=0;i<n;++i)
        {
            printf("%d ",ex[i]);
        }
        printf("\n");
    }
    for(i=0;i<n;++i)
    {
        if(vis[i]==1)
        {
            vis[i]=0;
            ex[p++]=a[i];
            dfs(ith+1);
            p--;
            vis[i]=1;
        }
    }
}

int main()
{
	int i;
    scanf("%d",&n);
    for(i=0; i<n; ++i)
    {
        a[i]=i+1;
        vis[i]=1;
    }
    p=0;
    dfs(0);
    return 0;
}



