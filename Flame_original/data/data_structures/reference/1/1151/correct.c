#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define cin(k) scanf("%d",&k)
int n;
int a[15],b[15];
void dfs(int n,int d)
{
	if(d>n)
	{
		for(int q=1;q<=n;q++)
			printf("%d ",a[q]);
		printf("\n");
	}
	for(int q=1;q<=n;q++)
	{
		if(!b[q])
		{
			a[d]=q,b[q]=1;
			dfs(n,d+1);
			b[q]=0;
		}
	}
}
signed main()
{
	cin(n);
	dfs(n,1);
}

