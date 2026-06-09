#include<stdio.h>

void exchange(int a[], int i, int j)
{
	int k;
	int temp=a[j];
	for(k=j;k>=i+1;k--)
	{
		a[k]=a[k-1];
	}
	a[i]=temp;
}

void exchange_back(int a[], int i, int j)
{
	int k;
	int temp=a[i];
	for(k=i;k<=j-1;k++)
	{
		a[k]=a[k+1];
	}
	a[j]=temp;
} 

void PrintResult(int a[], int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void function(int a[], int i, int j)
{
	int k;
	if(i==j)
	{
		PrintResult(a, j+1);
	}else
	{
		for(k=i;k<=j;k++)
		{
			exchange(a, i, k);
			function(a, i+1, j);
			exchange_back(a, i, k);
		}
	} 
}

int main()
{
	int a[20];
	int n;
	int i=0;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		a[i]=i+1;
	}
	function(a, 0, n-1);
	return 0;
}



