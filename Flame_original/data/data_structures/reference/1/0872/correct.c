#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define llo long long
#define max(A,B) A>B?A:B
int index(int k)
{
	int i=0,sum=1;
	for(;i<k-1;i++)
	{
		sum*=2;
	}
	return sum;
}
int a[15];
void swap(int p,int q)
{
	int t=a[q];
		
		
	int i=0,j=0;
	for(i=0;i<q-p;i++)
	{
		a[q-i]=a[q-1-i];
	}
	a[p]=t;
}
void deswap(int p,int q)
{
	int t=a[p];
		
		
	int i=0,j=0;
	for(i=0;i<q-p;i++)
	{
		a[p+i]=a[p+1+i];
	}
	a[q]=t;
}
void f(int p,int q)
{
	int i=0,j=0;
	if(p==q)
	{
		for(j=1;j<=q;j++)
		printf("%d ",a[j]);
		putchar(10);
		return;
	}

	
	
	for(i=p;i<=q;i++)
	{
		
		swap(p,i);
		
		f(p+1,q);
		deswap(p,i);
		
	}
	
		
	
}
int main()
{
	int n,i=0,j=0,t;
	
	scanf("%d",&n);
	for(j=1;j<=n;j++)
	{
		a[j]=j;
	}
	f(1,n);
	return 0;
	
}


