#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct a{
	int b;
	int c;
}a1[100000],a2[100000],a3[10000000],a4;
int main()
{
	int i,j,n,b1,c1,n1,n2,k=0;
	int z;
	scanf("%d%d",&b1,&c1);
	i=0;
	while(getchar()!='\n')
	{
		a1[i].b=b1;
		a1[i].c=c1;
		i=i+1;
		scanf("%d%d",&b1,&c1);
	}
	a1[i].b=b1;
	a1[i].c=c1;
	n1=i+1;
	scanf("%d%d",&b1,&c1);
	i=0;
	while(getchar()!='\n')
	{
		a2[i].b=b1;
		a2[i].c=c1;
		i=i+1;
		scanf("%d%d",&b1,&c1);
	}
	a2[i].b=b1;
	a2[i].c=c1;
	n2=i+1;
	n=n1*n2;
	for(i=0;i<n1;i=i+1)
	{
		for(j=0;j<n2;j=j+1)
		{
			a3[k].b=a1[i].b*a2[j].b;
			a3[k].c=a1[i].c+a2[j].c;
			k=k+1;
		}
	}
	for(i=0;i<n-1;i=i+1)
	{
		for(j=i+1;j<n;j=j+1)
		{
			if(a3[i].c<a3[j].c)
			{
				a4=a3[i];
				a3[i]=a3[j];
				a3[j]=a4;
			}
			if(a3[i].c==a3[j].c)
			{
				a3[i].b=a3[i].b+a3[j].b;
				a3[j].c=-1;
			}
		}
	}
	for(i=0;i<n;i=i+1)
	{
		if(a3[i].c>=0)
		printf("%d %d ",a3[i].b,a3[i].c);
	}
	return 0;
}

