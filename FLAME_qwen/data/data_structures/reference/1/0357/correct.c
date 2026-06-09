#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
int n;
int a[10],v[10];
void dfs(int x)
{
	if(x==n+1)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0)
		{
			a[x]=i ;
			v[i]=1;
			dfs(x+1);
			v[i]=0;
		}
	}
}
int main(){
	scanf("%d",&n);
	dfs(1);
	return 0;
return 0;
}



