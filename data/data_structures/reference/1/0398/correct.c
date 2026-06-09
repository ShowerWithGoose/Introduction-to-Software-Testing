#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int x[12],n;
int cmp(const void*a,const void*b)
{
	int*a1=(int*)a;
	int*b1=(int*)b;
	return *a1-*b1;
}
void hy(int a[],int b[])
{
	int i;
	for(i=0;i<n;i++)
	a[i]=b[i];
}
void fc(int m,int a[])
{
	int i,k,y[n];
	if(m==1)
	{
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	else
	{
		for(i=0;i<n;i++)
		{
			y[i]=a[i];
		}
		for(i=n-m,k=a[n-m];i<n;i++)
		{
			a[n-m]=a[i];a[i]=k;
			qsort(a+n-m+1,m-1,sizeof(a[0]),cmp);
			fc(m-1,a);
			hy(a,y);
		}	
	}
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		x[i]=i+1;
	fc(n,x);
	return 0;
}



