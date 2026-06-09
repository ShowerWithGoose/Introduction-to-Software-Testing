#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define N 200
int n;//几个数的全排列 
int c[N];//
int d[N];//
void DFS(int *,int *,int );

int main()
{
	scanf("%d",&n);
	DFS(c,d,1);
	return 0;
}


void DFS(int *a,int *b,int depth)
{
	int i;
	if(depth==n+1)
	{
		for(i=1;i<=n;i++)
		  printf("%d ",a[i]);
		printf("\n");
		return ;
	}
	
	for(i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			a[depth]=i;
			DFS(a,b,depth+1);
			b[i]=0;
		}
	}
	
}

