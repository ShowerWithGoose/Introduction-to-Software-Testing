#include<stdio.h>
#include<string.h>
#define MAX 10
int a[MAX];
int n;
int check(int num,int pos)
{
	if(pos==1)return 1;
	else
	{
		for(int i=1;i<=pos-1;i++)
		{
			if(a[i]==num)return 0;
		}
		return 1;
	}
}
void dfs(int pos)
{
	int i,j,tmp;
	if(pos>n)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
		puts("");
		return ;
	}
	for(i=1;i<=n;i++)
	{
		if(check(i,pos))
		{
			a[pos]=i;
			dfs(pos+1);
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
}

