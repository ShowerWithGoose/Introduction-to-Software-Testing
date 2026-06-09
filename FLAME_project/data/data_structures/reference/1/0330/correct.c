#include<stdio.h>
int a[10],b[10];
void p(int step,int n);
void p(int step,int n)
{
	if(step>=n)
	{
		for(int k=0;k<n;k++)
		{
			printf("%d ",a[k]);
		}
		printf("\n");
	}
	else{
		for(int i=1;i<=n;i++)
		{
			if(b[i]==0)
			{
				b[i]=1;
				a[step]=i;
				p(step+1,n);
				b[i]=0;	
			}
			
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	p(0,n);
	return 0;
	
	
	
	
}

