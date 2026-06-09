#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int a[10000];
	int i=-1,j=0,n,top=-1,b[200];
	int k=0;
	while(k!=-1)
	{
		scanf("%d",&k);
		a[j]=k;
		j=j+1;
	}
	n=j;
	for(j=0;j<n;j=j+1)
	{
		if(a[j]==1)
		{
			j=j+1;
			b[++i]=a[j];
		}
		if(a[j]==0)
		{
			if(i>=0)
			{
				printf("%d ",b[i]);
				i=i-1;
			}
			else
			printf("error ");
		}
	}
	return 0;
 } 

