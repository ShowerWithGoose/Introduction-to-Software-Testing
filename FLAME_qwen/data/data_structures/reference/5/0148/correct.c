#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
 

int main()
{
	long long a1[505],b1[505],a2[505],b2[505],c[505],d[505];
	long long i=1,m,n,j,l=1,k,num,temp;
	do
	{
		scanf("%lld %lld",&a1[i],&b1[i]);
		i++;
	}while(getchar()!='\n');
	m=i-1;
	i=1;
	do
	{
		scanf("%lld %lld",&a2[i],&b2[i]);
		i++;
	}while(getchar()!='\n');
	n=i-1;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			c[l]=a1[i]*a2[j];
			d[l]=b1[i]+b2[j];
			l++;
		}
	}
	num=l-1;
	for(l=1;l<=num;l++)
	{
		for(k=l+1;k<=num;k++)
		{
			if(d[l]<d[k])
			{
				temp=d[l];
				d[l]=d[k];
				d[k]=temp;
			
				temp=c[l];
				c[l]=c[k];
				c[k]=temp;
			}
			else if(d[l]==d[k])
			{
				if(c[l]!=0)
				{
					c[l]+=c[k];
					c[k]=0;
				}
				
			}
		}
			
	}
	for(l=1;l<=num;l++)
	{
		if(c[l]!=0)
		{
			printf("%lld %lld ",c[l],d[l]);
		}
	}
	
	return 0;
}

