//1_5
#include <stdio.h>

int a[10000]={},b[10000],x,k=0;

void print()
{
	for(int i=0;i<x;i++) printf("%d ",b[i]);
	printf("\n");
	return;
}
/*
void dfs(int n)
{
	if(n==0)
	{
		print();
		return ;
	}
	int l=0;
	for(int i=1;i<=n;i++)
	{
		int j=l+1;
		while(a[j]) j++;
		a[j]=1;
		b[k++]=j;
		l=j;
		dfs(n-1);
		a[j]=0;
		k--;
	}
	return;
}
*/

void dfs(int n)
{
	if(n==0)
	{
		print();
		return ;
	}
	int j=1;
	for(int i=1;i<=n;i++)
	{
		while(a[j]) j++;
		a[j]=1;
		b[k++]=j;
		dfs(n-1);
		a[j]=0;
		j++;
		k--;
	}
	return;
}

int main(int argc, char const *argv[])
{
	scanf("%d",&x);
	dfs(x);
	return 0;
}
