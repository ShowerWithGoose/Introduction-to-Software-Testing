#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<memory.h>
int a[15],depth,hasBeen[15]={0},n;
void output()
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void dfs(int depth)
{
	int i;
	if(depth>n)
	{
		output();
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(hasBeen[i]==0)
		{
			hasBeen[i]=1;
			a[depth]=i;
			dfs(depth+1);
			hasBeen[i]=0;
		}
	}
	return;
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
}




