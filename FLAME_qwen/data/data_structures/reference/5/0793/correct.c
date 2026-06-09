#include<stdio.h>
#include<string.h>
int main()
{
	char z;
	int m,n,a[100],b[100],c[100],d[100],w[100],s,t,p=0,q,i=0,k=0;
	do
	{
		scanf("%d",&n);
		z=getchar();
		a[i]=n;
		i++;
	}while(z!='\n');
	do
	{
		scanf("%d",&m);
		z=getchar();
		b[k]=m;
		k++;
	}while(z!='\n');
	for(s=0;s<i/2;s++)
	{
		for(t=0;t<k/2;t++)
		{
			c[p]=a[2*s+1]+b[2*t+1];
			d[p]=a[2*s]*b[2*t];
			w[p]=0;
			p++;
		}
	}
	for(s=1;s<p;s++)
	{
		for(t=0;t<s;t++)
		{
			if(c[s]>c[t])
			{
				q=c[s];c[s]=c[t];c[t]=q;
				q=d[s];d[s]=d[t];d[t]=q;
			}
		}
	}
	for(s=1;s<p;s++)
	{
		for(t=0;t<s;t++)
		{
			if(c[s]==c[t]) w[s]++,d[t]=d[s]+d[t];
		}
	}
	for(s=0;s<p;s++)
	{
		if(w[s]==0) printf("%d %d ",d[s],c[s]);
	}
	return 0;
}

