#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define ll long long

struct dot
{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
};
struct dot a[110];

int main()
{
	int n,i,flag,x1_,y1_,x2_,y2_,len=0,j;
	scanf("%d",&n);
	while(n--)
	{
		flag=0;
		scanf("%d%d%d%d",&x1_,&y1_,&x2_,&y2_);
		if(len==0) 
		{
			a[0].x1=x1_;
			a[0].y1=y1_;
			a[0].x2=x2_;
			a[0].y2=y2_;
			a[0].num++;
			len++;
		}
		else
		{
			for(i=0;i<len;i++)
			{
				if(a[i].x2==x1_&&a[i].y2==y1_)
				{
					a[i].x2=x2_;
					a[i].y2=y2_;
					a[i].num++;
					flag=1;
					break;
				}
				else if(a[i].x1==x2_&&a[i].y1==y2_)
				{
					a[i].x1=x1_;
					a[i].y1=y1_;
					a[i].num++;
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				a[len].x1=x1_;
				a[len].y1=y1_;
				a[len].x2=x2_;
				a[len].y2=y2_;
				a[len].num++;
				len++;
			}
		}
	}
	for(i=1;i<len;i++)
	{
		for(j=0;j<=i-1;j++)
		{
			if(a[j].num!=0)
			{
				if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
				{
					a[i].x2=a[j].x2;
					a[i].y2=a[j].y2;
					a[i].num+=a[j].num;
					a[j].num=0;
				}
				if(a[i].x1==a[j].x2&&a[i].y1==a[j].y2)
				{
					a[i].x1=a[j].x1;
					a[i].y1=a[j].y1;
					a[i].num+=a[j].num;
					a[j].num=0;
				}
			}
		}
	}
	int mx=0;
	for(i=0;i<len;i++)
	{
		if(a[i].num>mx) 
		{
			mx=a[i].num;
			j=i;
		}
	}
	printf("%d %d %d",mx,a[j].x1,a[j].y1);
	return 0;	
}

