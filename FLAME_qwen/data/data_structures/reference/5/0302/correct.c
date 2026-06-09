#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ll long long
struct multi
{
	ll a[114];
	ll x[114];
}m1,m2;
int main()
{
	int i=0,j=0,k=0;
	char c; 
	ll temp,tem;
	struct multi out;
	for(i=0;;i++)
	{
		scanf("%lld%lld",&m1.a[i],&m1.x[i]);
		scanf("%c",&c);
		if(c=='\n')
		break;
	}
	for(j=0;;j++)
	{
		scanf("%lld%lld",&m2.a[j],&m2.x[j]);
		scanf("%c",&c);
		if(c=='\n')
		break;
	}
	int m=i+1,n=j+1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			out.a[k]=m1.a[i]*m2.a[j];
			out.x[k]=m1.x[i]+m2.x[j];
			k++;
		}
	}
	for(i=k-1;i>0;i--)
		for(j=0;j<i;j++)
			if(out.x[i]>out.x[j])
			{
				temp=out.x[i];
				out.x[i]=out.x[j];
				out.x[j]=temp;
				tem=out.a[i];
				out.a[i]=out.a[j];
				out.a[j]=tem;
			}
	for(i=0;i<k;i++)
	{
		if(out.x[i]!=out.x[i+1]&&out.a[i]!=0)
			printf("%lld %lld ",out.a[i],out.x[i]);
		else if(out.x[i]==out.x[i+1])
		{
			for(j=0;j<114;j++)
				if(out.x[j+i]==out.x[i+j+1])
					out.a[i+j+1]=out.a[i+j]+out.a[i+j+1];
				else
				{
					if(out.a[i+j]!=0)
					{
						printf("%lld %lld ",out.a[i+j],out.x[i+j]);
						i=i+j;
						break;
					}
					else
					{
						i=i+j;
						break;
					}
				}
		}
		else
			continue;
	}
}

