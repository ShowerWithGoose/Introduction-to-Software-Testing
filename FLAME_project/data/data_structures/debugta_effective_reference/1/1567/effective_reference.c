#include<stdio.h>
#include<string.h>

void print(char a[],int N)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void swap(char a[],int p,int q)
{
	char temp=a[q];
	int i;
	for(i=q;i>p;i--)
	{
		a[i]=a[i-1];
	}
	a[p]=temp;
}

void qswap(char a[],int p,int q)
{
	int i,temp;
	temp=a[p];
	for(i=p;i<q;i++)
	{
		a[i]=a[i+1];
	}
	a[i]=temp;
	
}
void f(char a[],int p,int q)
{
	if(p==q) print(a,q+1);
	else
	{
		int i;
		for(i=p;i<=q;i++)
		{
			swap(a,p,i);
			f(a,p+1,q);
			qswap(a,p,i);
		}
	}
	
}
void m(char a[],int N)
{
	int i=0;
	for(i=0;i<N;i++)
	{
		a[i]=i+1;
	}
	
}

int main()
{
	int N;
	scanf("%d",&N);
	char a[10];
	m(a,N);
	f(a,0,N-1);
}



