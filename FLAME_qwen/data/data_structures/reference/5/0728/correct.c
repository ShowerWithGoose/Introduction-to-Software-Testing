#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
struct mul{
	int x;//系数 
	int y;//指数 
}fir[1000],sec[1000],end[1000000];
int main()
{
	int i=0,j=0,l=0,k=0,m=0,n=0,len1=0,len2=0,len3=0;
	int tmp=0;
	int p=0,q=0;
	for(i=0;;i++)
	{
		scanf("%d%d",&fir[i].x,&fir[i].y);
		if(getchar()=='\n')
		{
			break;
		}
	}
	len1=i+1;
	for(j=0;;j++)
	{
		scanf("%d%d",&sec[j].x,&sec[j].y);
		if(getchar()=='\n')
		{
			break;
		}
	}
	len2=j+1;
	for(k=0,m=0;m<len1;m++)
	{
		for(n=0;n<len2;n++,k++)
		{
			end[k].x=fir[m].x*sec[n].x;
			end[k].y=fir[m].y+sec[n].y;
		}
	}
	len3=k;
	for(q=0;q<len3;q++)
	{
		for(p=q+1;p<len3;p++)
		{
			if(end[q].y<end[p].y)
			{
				tmp=end[q].x;
				end[q].x=end[p].x;
				end[p].x=tmp;
				tmp=end[q].y;
				end[q].y=end[p].y;
				end[p].y=tmp;
			}
			else if(end[q].y==end[p].y)
			{
				end[q].x=end[q].x+end[p].x;
				end[p].x=0;
				end[p].y=0;
			}
		}
	}
	for(i=0;i<len3;i++)
	{
		if(end[i].x==0)
		{
			continue;
		}
		printf("%d %d ",end[i].x,end[i].y);
	}
	return 0;
}

