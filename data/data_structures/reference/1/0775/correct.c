#include<stdio.h>
#include<string.h>
#include<string.h>
#include<ctype.h>
int n,a[1000],b[1000];
void dfs(int x);
int main()
{
 	scanf("%d",&n);
 	dfs(1);
	return 0;
}
void dfs(int x)
{
	int i;
	if(x==n+1)
    {
        for(i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n");
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(b[i]==0)
        {
            a[x]=i;
            b[i]=1;
            dfs(x+1);
            b[i]=0;
        }
    }
    return;
}

