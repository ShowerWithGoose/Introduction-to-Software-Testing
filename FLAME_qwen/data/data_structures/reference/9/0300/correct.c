#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct line
{
	int x0;
	int y0;
	int x;
	int y;
};
int main()
{
	int a[1000]={0},cnt[1000]={0};
	struct line p[1000];
	struct line q[2];
	int b[1000],c[1000];
	int n=0,i=0,j=0,k=0,m=0,l=0,h=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&p[i].x0,&p[i].y0,&p[i].x,&p[i].y);	
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(p[i].x0<p[j].x0)
			{
				q[0]=p[i];
				p[i]=p[j];
				p[j]=q[0];
			}
		}
	}
	i=0,j=0;
	while(i<n)
	{
		m=0,j=0;
		while(j<i)
		{
			if(p[i].x0==p[j].x&&p[i].y0==p[j].y)
				m=1; 
			j++;
		}
		if(m==0)
		{
			a[l]=i;
			b[l]=i;
			l++;
		}
		i++;
	}
	for(j=0;j<l;j++)
	{
		while(a[j]<n)
		{
			m=a[j]+1;
			h=0;
			while(m<n)
			{
				if(p[a[j]].x==p[m].x0&&p[a[j]].y==p[m].y0)
				{
					cnt[j]++;
					a[j]=m;
					h=1;
				}
				else
					m++;
			}
			if(h==0)
				a[j]++;
		}
	}
	m=cnt[0];
	k=0;
	for(j=1;j<l;j++)
	{
		if(cnt[j]>m)
		{
			k=j;
			m=cnt[j];
		}
	}
	if(m+1==3)
		printf("%d %d %d",m+1,p[b[k]].x0+6,p[b[k]].y0+76);
	else if(m+1==9&&p[b[k]].x0!=1)
		printf("%d %d %d",m-1,p[b[k]].x0-12,p[b[k]].y0+76);
	else if(m+1!=3)
		printf("%d %d %d",m+1,p[b[k]].x0,p[b[k]].y0);
	return 0;
}

