#include<stdio.h>
void mmm(int *a,int *b,int n,int p)
{
	if(p==n+1)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d ",a[i]); 
		}
		printf("\n");
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(b[i]==0)
			{
				b[i]=1;
				a[p]=i;
				mmm(a,b,n,p+1);
				b[i]=0;
			}
		}
	}
}
int main()
{
	int n;
	
	int a[1005]={0};
	int b[1005]={0};
	scanf("%d",&n);
	mmm(a,b,n,1);
	return 0;
}

