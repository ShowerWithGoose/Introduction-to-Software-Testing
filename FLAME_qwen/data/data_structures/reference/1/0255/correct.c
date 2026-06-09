#include <stdio.h>
int a[1000]={0},b[1000]={0}; 
void DFSf(int n, int m);
int main()
{
	int N;
	scanf("%d",&N);
	DFSf(N,1);
	return 0;
}
void DFSf(int n, int m)
{
	int i;
	if (m<=n)
	{
		for (i=1;i<=n;i++)
		{
			if (b[i]==0)
			{
				a[m]=i;
				b[i]=1;
				DFSf(n,m+1);
				b[i]=0;
			}
		}
	}
	else if (m==n+1)
	{
		for (i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
		return;
	}
}



