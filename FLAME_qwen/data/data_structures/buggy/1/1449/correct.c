#include<stdio.h>

int a,b,m,n,x,p[1005],t;

void huan(int a,int b);
void pai(int m,int n);
void hui(int a,int b); 

int main()
{
	int j;
	scanf("%d",&x);
	for(j=1;j<=x;j++)
	{
		p[j]=j;
	}
	
	pai(1,x);
	
	return 0;
}

void pai(int m,int n)
{
	int k,i;
	if(m==n)
	{
		for(k=1;k<=x;k++)
		{
			printf("%d ",p[k]);
		}
		printf("\n");
	}
	else
	{
		for(i=m;i<=n;i++)
		{
			huan(m,i);
			pai(m+1,n);
			hui(m,i);
		}	
	}
}

void huan(int a,int b)
{
	int i;
	
	t=p[b];
	for(i=b-1;i>=a;i--)
	{
		p[i+1]=p[i];
	}
	p[a]=t;
}

void hui(int a,int b)
{
	int i;
	
	t=p[a];
	for(i=a+1;i<=b;i++)
	{
		p[i-1]=p[i];
	}
	p[b]=t;
}

