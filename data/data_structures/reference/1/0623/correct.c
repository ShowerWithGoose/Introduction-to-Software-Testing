#include<stdio.h>
int tem[15];
void pai(int,int,int[]);
int main()
{
	int a[15];
	int n;
	scanf("%d",&n);
	pai(0,n,a);
	return 0; 
}

void pai(int m,int n,int a[])
{
	int i;
	if(m>=n)
	{
		for(i=0;i<n-1;i++)
		{
			printf("%d ",a[i]);
		}
		printf("%d\n",a[i]);
		return;
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(tem[i]==0)
			{
				tem[i]=1;
				a[m]=i+1;
				pai(m+1,n,a);
				tem[i]=0;
			}
		}
	}
}

