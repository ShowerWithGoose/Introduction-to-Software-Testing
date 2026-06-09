#include<stdio.h>
int main()
{
	int a[100],b[100],c[1000],g[1000],i,j,k,d,f,x,y;
	char z[100];
	i=0;
	scanf("%d%c",&a[0],&z[0]);
	while(z[i]==' ')
	{
		i=i+1;
		scanf("%d%c",&a[i],&z[i]);
	}
	x=i;
	i=0;
	scanf("%d%c",&b[0],&z[0]);
	while(z[i]==' ')
	{
		i=i+1;
		scanf("%d%c",&b[i],&z[i]);
	}
	y=i;
	i=0;
	k=0;
	for(i=0;i<=x-1;i+=2)
	{
		for(j=0;j<=y-1;j+=2)
		{
			c[k]=a[i]*b[j];
			c[k+1]=a[i+1]+b[j+1];
			k+=2;
		}
	}
	j=0;
	d=k-2;
	g[0]=c[0];g[1]=c[1];
	for(i=2;i<=d;i+=2)
	{
		f=0;
		for(k=0;k<=j;k+=2)
		{
			if(c[i+1]==g[k+1])
			{
				g[k]=g[k]+c[i];
				f+=1;
			}
		}
		if(f==0)
		{
			j+=2;
			g[j]=c[i];g[j+1]=c[i+1];
		}
	}
	d=j;
	for(i=0;i<=d-2;i+=2)
	{
		for(j=0;j<=d-2-i;j+=2)
		{
			if(g[j+1]<=g[j+3])
			{
				f=g[j];
				g[j]=g[j+2];
				g[j+2]=f;
				f=g[j+1];
				g[j+1]=g[j+3];
				g[j+3]=f;
			}
		}
	}
	for(i=0;i<=d+1;i++)
	{
		printf("%d ",g[i]);
	}
}

