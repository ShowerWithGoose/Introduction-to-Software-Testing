#include<stdio.h>
int a[15]={0};
int b[15]={0};
void array(int n,int depth) 
{
	int i;
	if(depth==n+1)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",b[i]); 
		}
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			a[i]=1; 
			b[depth]=i;
			array(n,depth+1); 
			a[i]=0; 
		}
	}
}
int main()
{	
	int n,i;
	scanf("%d",&n);
	array(n,1);
	return 0;
}
