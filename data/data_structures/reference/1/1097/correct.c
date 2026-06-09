#include<stdio.h>
int n,check[11],ans[11];
void arrange(int rank)
{
	int i;
	if(rank>n)
	{
		for(i=1;i<=n;i++)printf("%d ",ans[i]);
		putchar('\n');
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(check[i]==0)check[i]=1,ans[rank]=i,arrange(rank+1),check[i]=0;
		
	}
	return ;
}
int main()
{scanf("%d",&n);
arrange(1);
return 0;
}



