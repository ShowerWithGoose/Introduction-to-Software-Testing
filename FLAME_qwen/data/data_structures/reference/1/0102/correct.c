#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[10005],n,used[10005],q[10005];
void queue(int n,int depth)
{
	int i,j;
	if (depth==n)
	{
		for (j=0;j<depth;j++)
		{
			printf("%d ",q[j]);
		}
		putchar('\n');
		return;
	}
	for (i=1;i<=n;i++)
	{
		if (used[i]==0)
		{
			q[depth]=a[i];
			used[i]=1;
			queue(n,depth+1);
			used[i]=0;
		}
	}
}
int main()
{
	int k;
	scanf("%d",&n);
	for (k=1;k<=n;k++)
	{
		a[k]=k;
	}
	queue(n,0);
	return 0;
}


