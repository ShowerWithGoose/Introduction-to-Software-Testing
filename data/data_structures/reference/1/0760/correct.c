#include<stdio.h>
int a[20]={0},b[20]={0},N;
void c(int n);
int main()
{
	scanf("%d",&N);
	c(1);
	return 0;
}
void c(int n)
{
	int i;
	if(n>N)
	{
		for(i=1;i<=N;i=i+1)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
	for(i=1;i<=N;i=i+1)
	{
		if(b[i]!=1)
		{
			b[i]=1;
			a[n]=i;
			c(n+1);
			b[i]=0;
		}
	}
}

