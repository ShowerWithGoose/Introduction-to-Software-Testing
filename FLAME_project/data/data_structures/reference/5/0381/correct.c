#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
long long a1[50],a2[50],b1[50],b2[50],c1[200],c2[200],d1[200],d2[200];
int main()
{
	int i,a,b,j,l,max=0;
	int *p,*t;
	char ch;
	i=0;
	do
	{
		scanf("%lld%lld%c",&a1[i],&a2[i],&ch);
		i++;
	}while(ch!='\n');
	a=i;
	i=0;
	do
	{
		scanf("%lld%lld%c",&b1[i],&b2[i],&ch);
		i++;
	}while(ch!='\n');
	b=i;
	int k=0;
	for(i=0;i<a;i++)
		for(j=0;j<b;j++)
		{
			c1[k]=a1[i]*b1[j];
			c2[k]=a2[i]+b2[j];
			k++;
		}
	l=k;
	for(i=0;i<l;i++)
		for(j=i+1;j<l;j++)
		{
			if(c2[i]==c2[j])
			{
				c1[i]+=c1[j];
				c1[j]=0;
			}
		}
	int tep2,tep1;
	for(i=0;i<l;i++)
	{
		for(j=0;j<l-i-1;j++)
		{
			if(c2[j]<c2[j+1])
			{
				tep1=c1[j];
				c1[j]=c1[j+1];
				c1[j+1]=tep1;
				tep2=c2[j];
				c2[j]=c2[j+1];
				c2[j+1]=tep2;
			}
		}
	}
	/*k=0;
	for(i=0;i<l;i++)
	{
		max=0;
		for(j=0;j<l;j++)
		{
			if(c2[j]>max&&c2[j]<d2[k-1]&&k>=1)
				max=c2[j];
			if(c2[j]>max&&k==0)
				max=c2[j];		
		}
		if(c2[i]>max&&k==0)
		{
			d2[k]=c2[i];
			d1[k]=c1[i];
			k++;
		}
		if(c2[i]>max&&c2[i]<d2[k-1]&&k>=1)
		{
			d2[k]=c2[i];
			d1[k]=c1[i];
			k++;
		}
	}*/
	for(i=0;i<l;i++)
		if(c1[i]!=0)
			printf("%d %d ",c1[i],c2[i]);
	return 0;
}

