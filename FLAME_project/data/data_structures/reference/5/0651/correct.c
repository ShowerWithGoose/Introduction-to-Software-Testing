#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a1[10000],a2[10000],b1[10000],b2[10000],c1[10000],c2[10000];//1为系数，2为指数 
int main()
{
	int i=0,j=0,m=0,n=0,k=0,s,q;
	char c=' ';
	while(c!='\n')
	{
		scanf("%d%d%c",&a1[i],&a2[i],&c);
		i++;
		m++;
	}
	c=' ';
	while(c!='\n')
	{
		scanf("%d%d%c",&b1[j],&b2[j],&c);
		j++;
		n++;
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			c1[k]=a1[i]*b1[j];
			c2[k]=a2[i]+b2[j];
			k=k+1;
		}
	}
	for(i=0;i<k-1;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(c2[i]<c2[j])
			{
				s=c2[i];
				c2[i]=c2[j];
				c2[j]=s;
				q=c1[i];
				c1[i]=c1[j];
				c1[j]=q;
   			} 
   			if(c2[i]==c2[j])
   			{
   				c1[i]=c1[i]+c1[j];
   				c1[j]=0;
   				c2[j]=0;
			   }
		}
	}
	for(i=0;i<k;i++)
	{
		if(c1[i]!=0)
		{
		printf("%d %d ",c1[i],c2[i]);
	}
	}
	return 0;
}

