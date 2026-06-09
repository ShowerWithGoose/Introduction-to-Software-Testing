#include<stdio.h>
int a[101],b[101],c[101],d[101],e[101],f[101],g[101],h[101],q[101];
int main()
{
	int n,i,j,z,max,m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	}
	for(i=0;i<n;i++)
	{
		f[i]=a[i];
		g[i]=b[i];
		h[i]=c[i];
		q[i]=d[i];
		e[i]=1;
		for(m=0;m<n;m++)
		{
		for(j=0;j<n;j++)
		{
			if(j==i)
			continue;
			if(a[j]==h[i]&&b[j]==q[i])
			{
				h[i]=c[j];
				q[i]=d[j];
				e[i]++;
			}
		}}
	}
	z=0;
	max=e[0];
	for(i=0;i<n;i++)
	{
		if(e[i]>max)
		{
			max=e[i];
			z=i;
		}
	}
	printf("%d %d %d",e[z],f[z],g[z]);
	return 0;
}

