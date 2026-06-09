#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define PI 3.14159265
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int n,a[11];
int mark[11];
void dfs(int op)
{
	int i;
	if(op>n)
	{
		for(i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(mark[i]==0)
		{
			a[op]=i;
			mark[i]=1;
			dfs(op+1);
			mark[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
}

