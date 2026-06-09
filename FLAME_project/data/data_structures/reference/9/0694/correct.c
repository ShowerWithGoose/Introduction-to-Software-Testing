#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
};
int order(const void *a,const void *b)
{
	struct line c=*(struct line*)a;
	struct line d=*(struct line*)b;
	if(c.x1>d.x1)
		return 1;
	else if(c.x1==d.x1)
		return 0;
	else
		return -1;
}
int main()
{
	struct line l[110];
	int judge[110];
	int quantity,max=0,x0,y0;
	scanf("%d",&quantity);
	for(int i=0;i<quantity;i++)
		scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	qsort(l,quantity,sizeof(l[0]),order);
	for(int i=0;i<quantity;i++)
	{
		if(judge[i]==1)
			continue;
		else
		{
			judge[i]=1;
			int preserve=i,length=1,xn=l[i].x2,yn=l[i].y2;
			for(int j=preserve+1;j<quantity;j++)
			{
				if(xn==l[j].x1&&yn==l[j].y1)
				{
					length++;xn=l[j].x2;yn=l[j].y2;judge[j]=1;
				} 
			}
			if(length>max)
			{
				max=length;x0=l[i].x1;y0=l[i].y1;
			}	
		}
	}
	printf("%d %d %d",max,x0,y0);
} 

