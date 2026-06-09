#include<stdio.h>
int check[11]={0},output[11],n;
void f(int cur)
{
	int i;
	if(cur==n)
	{
		for(i=0;i<n;i++)	printf("%d ",output[i]);
		putchar('\n');	
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(check[i])	continue;
		output[cur]=i;
		check[i]=1;
		f(cur+1);
		check[i]=0;
	}
}
int main()
{
	scanf("%d",&n);
	f(0);
	return 0;
}



