#include<stdio.h>
#include<string.h>
int a[100];
char b[100]={'\0'};
char c[100]={'\0'};
char d;
int main()
{
	int i=0,j=0,k,sum=0;
	while(c[j-1]!='=')
	{
		scanf("%d",&a[j]);
		scanf("%c",&c[j]);
		while(c[j]==' ')
		{
			scanf("%c",&c[j]);
		}	
		j++;
	}
	sum=a[0];
	for(k=0;k<j;k++)
	{
		if(c[k]=='*')
		{
			d=c[k-1];
			a[k+1]=a[k]*a[k+1];
			a[k]=0;
			c[k]=d;
		}
		if(c[k]=='/')
		{
			d=c[k-1];
			a[k+1]=a[k]/a[k+1];
			a[k]=0;
			c[k]=d;
		}
	}
	for(k=0;k+1<j;k++)
	{
		if(c[k]=='+')
		{
			sum=sum+a[k+1];
		}
		if(c[k]=='-')
		{
			sum=sum-a[k+1];
		}
	}
	printf("%d",sum);
 } 

