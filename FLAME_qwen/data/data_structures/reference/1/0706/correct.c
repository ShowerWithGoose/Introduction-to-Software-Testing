#include<stdio.h>
#include<stdlib.h>
int a[11],t[11];
void printArray(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
} 
void prem(int m,int n,int a[],int t[])
{
	if(m==n)
	printArray(a,n);
	else
	{
		int i;
		for(i=0;i<n;i++)
		{
			if(t[i]==0)
			{
				t[i]=1;
				a[m]=i+1;
				prem(m+1,n,a,t);
				t[i]=0;
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	prem(0,n,a,t);
	return 0;
}

