#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
struct dot
{
	struct dot * after;
	int x1,x2,y1,y2;
} ;

int main()
{
	int x;
	scanf("%d",&x);
	struct dot line[x];
	int i,j;
	for(i=0;i<x;i++)
	{
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		line[i].after=NULL;
	}
	for(i=0;i<x;i++)
		for(j=0;j<x;j++)
		{
			if(line[i].x2==line[j].x1&&line[i].y2==line[j].y1)
			{
				line[i].after=&line[j];
				break;
			}
		}
	int x0,y0,max=0;
	int num[x];
	for(i=0;i<x;i++)
	{
		num[i]=1;
		struct dot *p=line[i].after;
		while(p!=NULL)
		{
			num[i]++;
			p=p->after;
		}
		max=(num[i]>max)?num[i]:max;
	}
	for(i=0;i<x;i++)
	{
		if(max==num[i])
		{
			x0=line[i].x1;
			y0=line[i].y1;
			break;
		}
	}
	printf("%d %d %d",max,x0,y0);
	return 0;
}

