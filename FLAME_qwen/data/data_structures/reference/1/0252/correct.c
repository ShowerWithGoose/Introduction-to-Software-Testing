#include<stdio.h>
long long int factorial(int n)
{
	if(n==1) return 1;
	else return n*factorial(n-1);
}
void print(int *a,int n)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		printf("%d ",a[i]);
	}
	printf("%d\n",a[i]);
}
void fun(int *a,int n)
{
	int i,j;
	for(i=n-2;i>=0;i--)
	{
		if(a[i]<a[i+1])
		break;
	}
	int k=i,p=i+1;
	for(i=k+1;i<n;i++)
	{
		if(a[i]<a[p]&&a[i]>a[k])
		p=i;
	}
	int temp;
	temp=a[k];
	a[k]=a[p];
	a[p]=temp;
	for(i=k+1,j=n-1;i<j;i++,j--)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
}
int main()
{
	int a[10];
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		a[i]=i+1;
	}
	print(a,n);
	for(i=1;i<factorial(n);i++)
	{
		fun(a,n);
		print(a,n);
	}
	return 0;
} 


