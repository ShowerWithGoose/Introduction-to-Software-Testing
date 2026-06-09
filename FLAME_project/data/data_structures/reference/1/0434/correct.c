#include <stdio.h>

void arrange(int* ,int ,int );
void swap(int* ,int ,int );
void print (int* ,int );
int n,a[15];

int main()
{
	int i;
	scanf ("%d",&n);
	if (n==1)
	printf ("1");
	else if (n==2)
	printf ("1 2\n2 1");
	else
	{
		for (i=0;i<n;i++)
		a[i]=i+1;
		arrange(a,0,n-1);
	}

	return 0;
}

void arrange(int a[],int begin,int end)
{
	if (begin==end)
	print(a,end);
	else
	for (int i=0;i<=(end-begin);i++)
	{
		int temp,b[15];
		swap(a,begin,begin+i);
		for (int j=0;j<n;j++)
		b[j]=a[j];
		for (int j=begin+1;j<n;j++)
		for (int k=j;k<(n-1);k++)
		if (b[k]>b[k+1])
		{
			temp=b[k];
			b[k]=b[k+1];
			b[k+1]=temp;
		}
		arrange(b,begin+1,end);
	}	
}

void swap(int a[],int a1,int a2)
{
	int temp;
	temp=a[a1];
	a[a1]=a[a2];
	a[a2]=temp;
	
	return ;
}

void print (int a[],int end)
{
	for (int i=0;i<=end;i++)
	printf ("%d ",a[i]);
	printf ("\n");
}


