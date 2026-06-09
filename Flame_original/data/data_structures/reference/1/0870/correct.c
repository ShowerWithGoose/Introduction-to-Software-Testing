#include<stdio.h>
int a[15];
int book[15];
void xt(int n,int step)
{
	if(step>n)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(book[i]==0)
		{
			a[step]=i;
			book[i]=1;
			xt(n,step+1);
			book[i]=0;
		}
	}
	return;
}



int main()
{
	int n;
	scanf("%d",&n);
	xt(n,1);
	return 0;
}

