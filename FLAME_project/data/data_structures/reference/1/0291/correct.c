#include<stdio.h>
void deep(int *a,int *b,int n,int d)
{
	int i=1;
	if(d==n+1)
	{
		for(i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			a[d]=i;
			deep(a,b,n,d+1);
			b[i]=0;
		}
	}
 } 
int main()
{
	int n;
	scanf("%d",&n);
	int a[11]={0},b[11]={0};
	deep(a,b,n,1);
	return 0;
}

