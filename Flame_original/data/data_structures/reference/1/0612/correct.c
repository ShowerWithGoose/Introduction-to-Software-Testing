#include<stdio.h>
void qpl(int *a,int *b,int n,int ci)
{
	int i;
	if(ci==n+1)
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
		    a[ci]=i;
		    qpl(a,b,n,ci+1);
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
	qpl(a,b,n,1);
	return 0;
} 



