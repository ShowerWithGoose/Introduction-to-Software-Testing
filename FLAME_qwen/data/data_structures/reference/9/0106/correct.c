#include<stdio.h>
#include<string.h>

int lx,ly,rx,ry;
int n,num=0,max=1;

struct a
{
	int fx;
	int fy;
	int sx;
	int sy;
	int judge;
}loc[101];

void restart()
{
	int i;
	for(i=0;i<n;i++) loc[i].judge =0;
}

void gofrom(int a)
{
	loc[a].judge++;
	lx=loc[a].fx;ly=loc[a].fy;rx=loc[a].sx;ry=loc[a].sy;
	int i,j;
	for(i=0;i<n;i++)
	{
		if(loc[i].judge!=0) continue;
		if(loc[i].fx == lx && loc[i].fy == ly)
		{
			lx=loc[i].sx;
			ly=loc[i].sy;
			num++; 
			loc[i].judge ++;
			i=0;
		}
		else if(loc[i].sx == lx && loc[i].sy == ly)
		{
			lx=loc[i].fx;
			ly=loc[i].fy;
			num++; 
			loc[i].judge ++;
			i=0;
		}
	}
//	restart();
	for(i=0;i<n;i++)
	{
		if(loc[i].judge!=0) continue;
		if(loc[i].fx == rx && loc[i].fy == ry)
		{
			rx=loc[i].sx;
			ry=loc[i].sy;
			num++; 
			loc[i].judge ++;
			i=0;
		}
		else if(loc[i].sx == rx && loc[i].sy == ry)
		{
			rx=loc[i].fx;
			ry=loc[i].fy;
			num++; 
			loc[i].judge ++;
			i=0;
		}
	}
	restart();
}

int main()
{
	int i,j;
	int x1,y1,x2,y2;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d %d %d %d",&loc[i].fx,&loc[i].fy,&loc[i].sx,&loc[i].sy);
	for(i=0;i<n;i++)
	{
		gofrom(i);
		if(num>max)
		{
			max=num;
			x1=lx;y1=ly;x2=rx;y2=ry;
		}
		num=1;
	}
	printf("%d ",max);
	if(x1<x2) printf("%d %d",x1,y1);
	else printf("%d %d",x2,y2);
 } 

