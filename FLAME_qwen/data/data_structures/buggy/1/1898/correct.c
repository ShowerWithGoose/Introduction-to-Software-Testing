#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int f[10],a[10];
int n;
void d(int x)
{
	if(x==n)
	{
		int i=0;
		while(i<n)
		{
			printf("%d ",a[i]);
			i++;
		}
		printf("\n");
		return;
	}
	else
	{
		int i=1;
		while(i<=n)
		{
			if(!f[i])
			{
				a[x]=i;
				f[i]=1;
				d(x+1);
				f[i]=0;
			}
			i++;
		}
	}
}
int main()
{
	scanf("%d",&n);
	d(0);
	return 0;
}

