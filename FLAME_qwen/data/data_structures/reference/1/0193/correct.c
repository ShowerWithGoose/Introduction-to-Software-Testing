#include<stdio.h>
int n,x;
int a[20],b[20];

void qpl(int x)
{
	int i;
	if(x==n+1)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		return ;
	}
	for(i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			a[x]=i;
			qpl(x+1);
			b[i]=0;
		}
	}
	return;
}

int main()
{
	scanf("%d",&n);
	qpl(1);
	return 0;
}

