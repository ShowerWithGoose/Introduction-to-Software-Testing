#include<stdio.h>
struct point
{
	int x[2],y[2];
}t;
int main()
{
	int n,i,j,e1=0,e2=0,n_=0;
	struct point p[101];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&p[i].x[0],&p[i].y[0],&p[i].x[1],&p[i].y[1]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(p[i].x[0]>p[j].x[0])
			{
				t=p[i];
				p[i]=p[j];
				p[j]=t;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		int n2=1;//n2为每条线段长度，n_为最长 
		int k=i;
		for(j=i+1;j<=n;j++)
		{
			if(p[k].x[1]==p[j].x[0]&&p[k].y[1]==p[j].y[0])
			{
				n2++;
				k=j;
			}
		}
		if(n2>=n_)
		{
			n_=n2;
			e1=p[i].x[0];
			e2=p[i].y[0];
		}
	}
	printf("%d %d %d",n_,e1,e2);
	return 0;
}

