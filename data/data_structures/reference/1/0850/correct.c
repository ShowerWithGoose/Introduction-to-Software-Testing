#include<stdio.h>	
void place(int a[],int b[],int m,int n)
{
	int i;
	if(m==n)
	{
		for(i=0;i<n-1;i++)
		{
			printf("%d ",a[i]);
		}
		printf("%d\n",a[i]);
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			if(b[i]==0)
			{
				b[i]=1;
				a[m]=i;
				place(a,b,m+1,n);
				b[i]=0;
			}
		}
	}
}
int num[100]={0},jud[100]={0}; 
int main()
{	
	int N;
	scanf("%d",&N);
	place(num,jud,0,N);
	return 0;
}



