#include<stdio.h>

int a[15],b[15];
void allr(int *x,int *y,int n,int count)
{
	int i;
	if(count==n+1)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",x[i]);
		}
		printf("\n");
		return;
	}
	
	for(i=1;i<=n;i++)
	{
		if(y[i]==0)
		{
			y[i]=1;
			x[count]=i;
			allr(x,y,n,count+1);
			y[i]=0;
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	allr(a,b,n,1);
	
	return 0;
} 

