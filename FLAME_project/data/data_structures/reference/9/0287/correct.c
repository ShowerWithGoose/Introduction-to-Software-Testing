#include<stdio.h>
struct _line{
	int x1;
	int y1;
	int x2;
	int y2;
	struct _line *next;
}line[505];
int main()
{
	int n,i,j,k,fmax=0,cmax=0;
	struct _line *p,*q,max;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		line[i].next=NULL;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==i)	continue;
			if(line[i].x2 ==line[j].x1 &&line[i].y2 ==line[j].y1 )
			{
				line[i].next =&line[j];
			}
		}
	}
	for(i=0;i<n;i++)
	{
		cmax=0;
		p=&line[i];
		while(p!=NULL)
		{
			cmax++;
			p=p->next;
		}
		if(cmax>fmax)
		{
			fmax=cmax;
			q=&line[i];
		}
	}
	printf("%d %d %d",fmax,q->x1,q->y1);
	return 0;
}

