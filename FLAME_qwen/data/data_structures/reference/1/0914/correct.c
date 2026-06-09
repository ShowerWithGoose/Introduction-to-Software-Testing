#include <stdio.h>
#include <string.h>
int num[12],c[12];
int n=0;
void rem(int q)
{
	int m=0;
	while(num[m]!=q)
	{
		m++;
	}
	while(m<10)
	{
		num[m]=num[m+1];
		m++;
	}
}
void init()
{
	int m=1;
	while(m<n)
	{
		num[m]=m;
		m++;
	}
	num[n]=n;
	num[n+1]=0;
	num[0]=0;
}
int next()
{
	int m=0,t=-1;
	m=n;
	while(m>0)
	{
		if(c[m]+m!=n+1)
		{
			c[m]=c[m]+1;
			t=m;
			break;
		}
		m--;
	}
	if(t!=-1)
	{
		while(t<n)
		{
			t++;
			c[t]=1;
		}
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	int q=0,s=0;
	scanf("%d",&n);
	while(q<12)
	{
		c[q]=1;
		q++;
	}
	q=0;
	while(q!=1)
	{
		init();
		s=0;
		while(s<n)
		{
			s++;
			printf("%d ",num[c[s]]);
			rem(num[c[s]]);
		}
		q=next();
		printf("\n");
	}
	return 0;
}



