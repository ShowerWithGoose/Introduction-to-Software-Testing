#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct f{
	int x1;
	int y1;
	int x2;
	int y2;
	struct f *next;
}c[122];
int main()
{
	int n,i,s,m=0,x,y,k;
	struct f *p;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	scanf("%d %d %d %d",&c[i].x1,&c[i].y1,&c[i].x2,&c[i].y2);
	c[i].next=NULL;
	for(k=0;k<i;k++)
	{
		if(c[i].x1==c[k].x2&&c[i].y1==c[k].y2)
		c[k].next=&c[i];
		else if(c[i].x2==c[k].x1&&c[i].y2==c[k].y1)
		c[i].next=&c[k];
	}
	}
	for(i=0;i<n;i++)
	{
		p=&c[i];
		s=1;
		while(p->next!=NULL)
		{
		p=p->next;
		s++;
		}
		if(s>m)
		{
			x=c[i].x1;
			y=c[i].y1;
			m=s;
		}
	}
	printf("%d %d %d",m,x,y);
	return 0;
}

