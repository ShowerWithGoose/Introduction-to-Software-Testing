#include<stdio.h>
#include<stdlib.h>
int judge[100],a[100];
void dfs(int , int );
int main()
{
    int n;
    scanf("%d",&n);
    int num=1;
    dfs(num,n);
    return 0;
}
void dfs(int num, int n)
{
    int i;
    if(num==n+1)
	{
        for(i=1;i<=n;i++)
		{
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    else
	{
        for(i=1;i<=n;i++)
		{
            if(judge[i]==0)
			{
                a[num]=i;
                judge[i]=1;
                dfs(num+1,n);
                judge[i]=0;
            }
        }
    }
}


