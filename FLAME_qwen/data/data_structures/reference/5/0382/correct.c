#include<stdio.h>
struct x
{
	int a;
	int b;
}x[10000];
struct y
{
	int a;
	int b;
}y[10000];
struct z
{
	int a;
	int b;
}z[10000];
struct q
{
	int a;
	int b;
}q[10000],t;
int main()
{
	int A,B,m=0,n=0,i,j,k;
	while(scanf("%d%d",&A,&B)!=EOF)
	{
		x[m].a=A;
		x[m].b=B;
		m++;
		if (getchar() == '\n')
		break;
	}
	while(scanf("%d%d",&A,&B)!=EOF)
	{
		y[n].a=A;
		y[n].b=B;
		n++;
	}
	k=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			z[k].a=x[i].a*y[j].a;
			z[k].b=x[i].b+y[j].b;
			k++;
		}
	}
	int l;
	for(i=0;i<k;i++)
	{
		l=z[i].a;
		for(j=i+1;j<k;j++)
		{
			if(z[i].b==z[j].b)
			{
				l+=z[j].a;
				z[j].a=0;
				z[j].b=0;
			}
		}
		q[i].a=l;
		q[i].b=z[i].b;
	}
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(q[i].b<q[j].b)
			{
				t=q[i];
				q[i]=q[j];
				q[j]=t;
			}
		}
	}
	for(i=0;i<k;i++)
	{
		if(q[i].a!=0)
		printf("%d %d ",q[i].a,q[i].b);
	}
	return 0;
}

