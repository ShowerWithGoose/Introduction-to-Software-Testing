#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int a[20];
	int n;
int book[20];
void func(int m)
{
	int i,j;
	if (m==n+1) 
	{
		for (i=1;i<=n-1;i++)
		printf("%d ",a[i]);
		printf("%d\n",a[n]);
		return;
	}
	for (i=1;i<=n;i++)
	{
		if (book[i]==0)
		{
			book[i]=1;
			a[m]=i;
			func(m+1);
			book[i]=0;
		}
	 }
	 return; 
}
int main()
{
	scanf("%d",&n);
	func(1);
	return 0;
}


