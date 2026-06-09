#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
void qpl(int k,int a[]);//х╚ееап 
int b[15];
int n;
int main()
{
  int i,k;
  int a[15];
  for(i=1;i<=10;i++) 	a[i]=i;
  scanf("%d",&n);
  k=n;
  qpl(k,a);
  return 0;
}

void qpl(int k,int a[])
{
	int i,temp,j,s;
	if(k==1) 
	{
	  for(i=1;i<=n;i++)
	   printf("%d ",a[i]);
	  printf("\n");
    }
	else
	 {
	  for(i=n-k+1;i<=n;i++)
	  {
	  	s=a[i];
		for(j=i-1;j>=n-k+1;j--) a[j+1]=a[j];
		a[n-k+1]=s;
		qpl(k-1,a);
		s=a[n-k+1];
		for(j=n-k+2;j<=i;j++) a[j-1]=a[j];
		a[i]=s;
	  } 
    }
}


