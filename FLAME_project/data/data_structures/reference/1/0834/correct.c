#include<stdio.h>	
int used[12]={0},a[12];
int n;
void f(int m,int n);
int main()
{
	scanf("%d",&n);
	f(1,n);
	return 0;
 } 
 void f(int m,int n)
 {
 	int i;
 	if(m==n+1)
 	{
 		for(i=1;i<=n;i++)
 		printf("%d ",a[i]);
 		printf("\n");
 		return;
	}
	for(i=1;i<=n;i++)
	{
		if(used[i]==0)
		{
		    a[m]=i;
			used[i]=1;
			f(m+1,n);
			used[i]=0;
		}
	}
 }



