#include<stdio.h>
typedef struct term
{
	long long a;
	long long n;
}term;
void integrate(term poly3[],int len3)
{
	int i=1,j=1;
	for(i=1;i<=len3;i++)
	{
		for(j=i+1;j<=len3;j++)
		{
			if(poly3[i].n==poly3[j].n&&poly3[j].n!=-1)
			{
				poly3[i].a+=poly3[j].a;
				poly3[j].n=-1;
			}
		}
	}
}
void sort(term poly3[],int len3)
{
	int i=1,j=1;
	for(i=1;i<=len3;i++)
	{
		for(j=1;j<=len3-i;j++)
		{
			if(poly3[j].n<poly3[j+1].n)
			{
				term tmp=poly3[j];
				poly3[j]=poly3[j+1];
				poly3[j+1]=tmp;
			}
		}
	}
}
int main()
{
	term poly1[50],poly2[50],poly3[100];
	term buf[100];
	int i=1,j=1,k=1;
	int len1=1,len2=0,len3=0,buflen=0;
	while(scanf("%lld%lld",&buf[i].a,&buf[i].n)!=EOF)
	{
		i++;
		buflen++;
	}
	poly1[1]=buf[1];
	for(i=2;i<=buflen;i++)
	{
		if(buf[i].n<poly1[i-1].n)
		{
			poly1[i]=buf[i];
			len1++;
		}
		else
		{
			break;
		}
	}
	for(j=i;j<=buflen;j++)
	{
		poly2[j-i+1]=buf[j];
		len2++;
	}
	for(i=1;i<=len1;i++)
	{
		for(j=1;j<=len2;j++)
		{
			poly3[k].a=poly1[i].a*poly2[j].a;
			poly3[k].n=poly1[i].n+poly2[j].n;
			len3++;
			k++;
		}
	}
	integrate(poly3,len3);
	sort(poly3,len3);
	for(i=1;i<=len3;i++)
	{
		if(poly3[i].n!=-1)
		{
			printf("%lld %lld ",poly3[i].a,poly3[i].n);
		}
	}
	return 0;
}
