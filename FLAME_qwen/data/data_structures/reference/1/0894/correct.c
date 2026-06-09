#include<stdio.h>
void DFS(int a[],int b[],int depth,int n);
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	int a[100]={0};
	int b[100]={0};
	DFS(a,b,1,n);
	return 0;
}
void DFS(int a[],int b[],int depth,int n)
{
	int i,j,k;
	if(depth==n+1)
	{
		for(i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n"); 
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			if(b[i]==0)
			{
				b[i]=1;
				a[depth]=i;
				DFS(a,b,depth+1,n);
				b[i]=0;
			}
		}
	}
}

