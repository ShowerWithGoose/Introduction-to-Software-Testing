#include<stdio.h>
#define int long long
int flg=0;

int read(){    //快读，读入速度显著快于cin,scanf，但只能读整数
	int x=0,f=1;char ch=getchar();//x为读入整数的绝对值，f为读入数的符号
	while(ch<'0'||ch>'9'){//读取符号
		if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){//读取数
		x=x*10+ch-'0';ch=getchar();}
	if(ch=='\n')
		flg=1;
	return x*f;//返回数×符号
}


struct node
{
	int a,x;
}x[500],y[500],z[5005];

int n,m,k;

struct node mult(struct node a,struct node b)
{
	struct node c;
	c.a=a.a*b.a;
	c.x=a.x+b.x;
	return c;
}


void sort()
{
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(z[j].x<z[j+1].x)
			{
				struct node tmp=z[j];
				z[j]=z[j+1];
				z[j+1]=tmp;
			}
		}
	}
}

signed main()
{
	while(flg==0)
	{
		x[n].a=read();
		x[n++].x=read();
	}
	flg=0;
	while(flg==0)
	{
		y[m].a=read();
		y[m++].x=read();
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			z[k++]=mult(x[i],y[j]);
		}
	}
	sort();
	for(int i=0;i<k-1;i++)
		if(z[i].x==z[i+1].x)
		{
			z[i+1].a+=z[i].a;
			z[i].a=0,z[i].x=0;
		}
	sort();
	for(int i=0;i<k;i++)
		if(z[i].a!=0)
		printf("%d %d ",z[i].a,z[i].x);
	return 0;
}

