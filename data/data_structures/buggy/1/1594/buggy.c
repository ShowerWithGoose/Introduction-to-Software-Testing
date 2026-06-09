#include <stdio.h>
#include<string.h>


void swap1(int in[],int x,int y)
{
	int mid=in[y];
	for(int i=y;i>=x+1;i--)
	{
		in[i]=in[i-1];
	}
	in[x]=mid;
}

void swap2(int in[],int x,int y)
{
	int mid=in[x];
	for(int i=x;i<=y-1;i++)
	{
		in[i]=in[i+1];
	}
	in[y]=mid;
}

void print(int in[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",in[i]);
	}
	printf("\n");
}

void out(int in[],int l,int r,int n)
{
	if(l==r)
	{
		print(in,n);
	}
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(in,l,i);
			out(in,l+1,r,n);
			swap2(in,l,i);
		}
	}
}
int in[3628805];
int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		in[i]=i+1;
	}
	
	out(in,0,n-1,n);
	return 0;
}

