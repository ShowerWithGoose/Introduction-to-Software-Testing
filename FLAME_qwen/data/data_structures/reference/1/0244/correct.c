#include<stdio.h>
void DfsFullPermutation(int *a, int *b, int n , int depth)   
{
	int i;
	if(depth==n+1)   
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",a[i]);  
		}
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(b[i]==0)  
		{
			b[i]=1;  
			a[depth]=i;
			DfsFullPermutation(a,b,n,depth+1);
			b[i]=0;
		}
	}
}
int main()
{	
	int n,i;
	int a[100]={0};
	int b[100]={0};
	scanf("%d",&n);
	DfsFullPermutation(a,b,n,1);
	return 0;
}


