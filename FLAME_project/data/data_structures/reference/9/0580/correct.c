#include <stdio.h>
struct line
{
	int x;
	int y;
	int xx;
	int yy;
	int num;	
};
int main()
{
	struct line l[100];
	int n,i,j,x1[100],y1[100],x2[100],y2[100],k=0,x3,y3,t=0,max=0,maxi;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(x1[j]>x1[j+1])
			{
				x3=x1[j];
				x1[j]=x1[j+1];
				x1[j+1]=x3;
				y3=y1[j];
				y1[j]=y1[j+1];
				y1[j+1]=y3;
				x3=x2[j];
				x2[j]=x2[j+1];
				x2[j+1]=x3;
				y3=y2[j];
				y2[j]=y2[j+1];
				y2[j+1]=y3;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		t=0;
		for(j=0;j<k;j++)
		{
			if(l[j].xx==x1[i] && l[j].yy==y1[i])
			{
				l[j].xx=x2[i];
				l[j].yy=y2[i];
				l[j].num++;
				t=1;
			}
		}
		if(t==0)
		{
			l[k].x=x1[i];
			l[k].y=y1[i];
			l[k].xx=x2[i];
			l[k].yy=y2[i];
			l[k].num=1;
			k++;
		}
	}
	for(i=0;i<k;i++)
	{
		if(l[i].num>max)
		{
			max=l[i].num;
			maxi=i;
		}
	}
	printf("%d %d %d",l[maxi].num,l[maxi].x,l[maxi].y);
	return 0;
}

