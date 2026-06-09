#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int b[100];
int main()
{
	int n;
	scanf("%d",&n);
	int a[100][4],c[4];
	int i,j,k,p;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j][0]>a[j+1][0])
			{
				for(k=0;k<4;k++)
				{
				p=a[j][k];
				a[j][k]=a[j+1][k];
				a[j+1][k]=p;
				}
			}
		}
	}//Ã°ÅÝÅÅÐò
/*	for(i=0;i<n;i++)
	{
		printf("%d %d %d %d\n",a[i][0],a[i][1],a[i][2],a[i][3]);
	}*/
	for(i=0;i<n;i++)
	{
		b[i]=1;
		for(k=0;k<4;k++)
		{
			c[k]=a[i][k];
		}
		for(j=i+1;j<n;j++)
		{
			if(c[2]==a[j][0]&&c[3]==a[j][1])
			{
				b[i]=b[i]+1;
				for(k=0;k<4;k++)
		        {
			        c[k]=a[j][k];
		        }
			}
		}
	}
	int max=b[0],flag;
	for(i=0;i<n;i++)
	{
		if(b[i]>max)
		{
			max=b[i];
			flag=i;
		}
	}
	printf("%d %d %d",max,a[flag][0],a[flag][1]);
	return 0;
 } 

