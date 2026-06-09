#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long
int main()
{
	int a[100]={0},b[100]={0},c[100]={0};
	int i,j,k,s,m=0,n=0,t=0,temp1,temp2;
	for(i=0;k!='\n';i++)
	{
		scanf("%d",&a[i]);
		k=getchar();
		m++;
	}
	for(i=0;s!='\n';i++)
	{
		scanf("%d",&b[i]);
		s=getchar();
		n++;
	}
	for(i=0;i<m;i+=2)
	{
		for(j=0;j<n;j+=2)
		{
			c[t]=a[i]*b[j];
			c[t+1]=a[i+1]+b[j+1]; 
			t+=2;
		}
	}
	for(i=1;i<t;i+=2)
	{
		for(j=i+2;j<t;j+=2)
		{
			if(c[i]==c[j])
			{
				c[i-1]+=c[j-1];
				c[j]=0;
				c[j-1]=0;
			}
		}
	}
	for(i=1;i<t;i+=2)
	{
		for(j=i+2;j<t;j+=2)
		{
			if(c[i]<c[j])
			{
				temp1=c[i];
				c[i]=c[j];
				c[j]=temp1;
				temp2=c[i-1];
				c[i-1]=c[j-1];
				c[j-1]=temp2;
			}
		}
	}
	for(i=0;i<t;i+=2)
	{
		if(c[i]==0)
		{
			continue;
		}
		else{
			printf("%d %d ",c[i],c[i+1]);
		}
	}
    return 0;
}
/*10 80000 2 6000 7 300 5 10 18 0
3 6000 5 20 8 10 6 0*/

