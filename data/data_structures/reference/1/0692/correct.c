#include<stdio.h>
int num[11],ans[10];
void f(int n,int c)
{
	int i;
	if(c==n)
	{
		for(i=0;i<n;i++)
		printf("%d ",ans[i]);
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(num[i]==0)
		{
			ans[c]=i;
			num[i]=1;
			f(n,c+1);
			num[i]=0;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	f(n,0);
	return 0;
}

