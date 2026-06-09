#include<stdio.h>
void fullpermutation(int*, int*, int, int);
int main()
{	
	int n,i;
	int a[100]={0};
	int b[100]={0};
	scanf("%d",&n);
	fullpermutation(a,b,n,1);
	return 0;
}
void fullpermutation(int *a, int *b, int n , int times)
{
	int i;
	if(times==n+1)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
		putchar(10);
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			a[times]=i;
			fullpermutation(a,b,n,times+1);
			b[i]=0;
		}
	}
}


