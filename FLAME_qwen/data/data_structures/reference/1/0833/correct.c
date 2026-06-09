#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>
int n,c[15];
void f(int,int[]);

int main() 
{
int i,j,a[15];
scanf("%d",&n);
for(i=1;i<=n;i++)
a[i]=i;
f(n,a);
	return 0;	
	}
	
	
void f(int h,int a[])
{
	int i,j,k,b[15];
	
	for(i=n-h+1;i<=n;i++)
	{
		b[n-h+1]=a[i];
		for(j=n-h+2;j<=i;j++)
		b[j]=a[j-1];
		for(j=i+1;j<=n;j++)
		b[j]=a[j];
		for(j=n-h+1;j<=n;j++)
		c[j]=b[j];

       if(h!=1)
		f(h-1,b);}
					if(h==1)
	 {for(i=1;i<=n;i++)
	   	  printf("%d ",c[i]);
	printf("\n");return;		 }
	}
	
	


	
	
	





