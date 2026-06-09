#include<stdio.h>
int n,a[20];
void exchange(int a[],int p,int q);
void rank(int a[],int p,int q);
int main()
{
	int i;
	scanf("%d",&n);
	for( i=0;i<n;i++)
	{
		a[i]=i+1;
	}
	rank(a,0,n-1);
	return 0;
} 
void exchange(int a[],int p,int q)
{
	int m,l;
	m=a[q];
	for(l=q;l>p;l--)
	{
		a[l]=a[l-1];
	}
	a[p]=m;
}
void back(int a[],int p, int q)
{
	int l,m=a[p];
	for(l=p;l<q;l++)
	{
		a[l]=a[l+1];
	}
	a[q]=m;
}
void rank(int a[],int p,int q)
{
	if(p==q)
	{
		int j;
		for( j=0;j<n;j++)
		{
			printf("%d ",a[j]);
		}
		printf("\n");
		return ;
	}
	else
	{
		int k;
		for( k=p;k<=q;k++)
		{
			exchange(a,p,k);
			rank(a,p+1,q);
			back(a,p,k);
		}
	}
}


