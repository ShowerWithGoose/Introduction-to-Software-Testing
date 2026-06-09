#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define pi 3.14159265

int a[100],b[100],c[100],d[100],i,j,k,max1,max2,e[100],f[100],temp;
char s;
int main()
{
	while(1)
	{
		scanf("%d%d%c",&a[i],&b[i],&s);i++;
		if(s=='\n')break;
	}
	while(1)
	{
		scanf("%d%d%c",&c[j],&d[j],&s);j++;
		if(s=='\n')break;
	}
	max1=i;max2=j;int max=max1*max2;
	for(i=0,j=0,k=0;i<max;i++)
	{
		e[i]=a[j]*c[k];
		f[i]=b[j]+d[k++];
		if(k==max2)k=0,j++;
	}
	for(i=0;i<max;i++)
	{
		for(j=i+1;j<max;j++)
		{
			if(f[i]==f[j])
			{
				e[i]+=e[j];
				e[j]=0;
			}
		}
	}
	for(i=0;i<max-1;i++)
	{
		for(j=0;j<max-i-1;j++)
		{
			if(f[j]<f[j+1])
			{
				temp=f[j];
				f[j]=f[j+1];
				f[j+1]=temp;
				
				temp=e[j];
				e[j]=e[j+1];
				e[j+1]=temp;
			}
		}
	}
	for(i=0;i<max;i++)
	{
		if(e[i]!=0)printf("%d %d ",e[i],f[i]);
	}
	
	return 0;
}



