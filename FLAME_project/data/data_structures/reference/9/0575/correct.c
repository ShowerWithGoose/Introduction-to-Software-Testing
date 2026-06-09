#include<stdio.h>
struct line
{
	int flag;
	int x1,y1,x2,y2;
}a[105],b;

int main()
{
	int n,i,j,k,m1=0,m2=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		a[i].flag=0;
	}
	for(i=0;i<n;i++)
	{
		if(a[i].flag==0)//start
		{
			m2++;
			a[i].flag=1;
			k=i;//repeat
			j=k;
			for(;j<n;j++)//behind
			{
				if(((a[j].x1)==(a[k].x2))&&((a[j].y1)==(a[k].y2))&&a[j].flag==0)
				{
					a[j].flag=1;
					m2++;
					k=j;
					j=i;
				}
			}
			k=i;//repeat
			j=k;
			for(;j<n;j++)//before
			{
				if(((a[j].x2)==(a[k].x1))&&((a[j].y2)==(a[k].y1))&&a[j].flag==0)
				{
					a[j].flag=1;
					m2++;
					k=j;
					j=i;
				}
			}
		}
		if(m2>m1)
		{
			m1=m2;
			b=a[k];
		}
		m2=0;
	}
	printf("%d %d %d",m1,b.x1,b.y1);
	return 0;
}

