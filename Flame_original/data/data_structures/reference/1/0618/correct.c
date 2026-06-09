#include<stdio.h>
#include<string.h>
int a[100];
void swap(int begin,int end)
{
	int t=a[end],i;
	for(i=end-1;i>=begin;i--)
	{
		a[i+1]=a[i];
	}
	a[i+1]=t;
}
void reswap(int begin,int end)
{
	int t=a[begin],i;
	for(i=begin;i<end;i++)
	{
		a[i]=a[i+1];
	}
	a[i]=t;
}
void fullarray(int begin ,int end)
{
	int i;
	if(begin>=end)
	{
		for(i=0;i<end;i++) printf("%d ",a[i]);
		printf("\n");
	}
	else
	{
		for(i=begin;i<end;i++)
		{
			if(begin!=i) swap(begin,i);
			fullarray(begin+1,end);
			if(begin!=i) reswap(begin,i);
		}
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=i+1;
	}
	fullarray(0,n);
	return 0;
}

