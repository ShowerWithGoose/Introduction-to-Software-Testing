#include<stdio.h>/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdlib.h>
long long f(int n)
{
	if(n<=1)
	{
		return 1;
	}
	return n*f(n-1);
}
int swap1(int arr[], int a, int b)
{
	for(int k=b;k>a;k--)
	{
		int temp=arr[k];
		arr[k]=arr[k-1];
		arr[k-1]=temp;
	}
}
int swap2(int arr[], int a, int b)
{
	for(int i=b;i<a;i++)
	{
		int temp=arr[i];
		arr[i]=arr[i+1];
		arr[i+1]=temp;
	}
}
void perm(int a[], int begin, int n)
{
	if(begin==n)
	{
		for(int i=0;i<=n;i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	else
	{
		for(int j = begin;j<=n;j++)
		{
			swap1(a, begin, j);
			perm(a, begin+1, n);
			swap2(a, j, begin);
		}
	}
}
int main()
{
	
	int n, i;
	int* a;
	scanf("%d", &n);
	a=(int*)calloc(n, sizeof(int));
	for(i=0;i<n;i++)
	{
		a[i]=i+1;
	}
	perm(a, 0, n-1);
	return 0;
}

