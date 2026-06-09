#include <stdio.h>
#include <stdlib.h>

struct dot
{
	int xf;
	int yf;
	int xl;
	int yl;
	struct dot *link;
};

int main ()
{
	int x1,x2,y1,y2,sum,i,cnt=1,max=0;
	struct dot *first,*p,*q,*result,*r,*s;
	scanf ("%d",&sum);
	
	result=(struct dot *)malloc(sizeof(struct dot));
	p=(struct dot *)malloc(sizeof(struct dot));
	first=p;
	scanf ("%d%d%d%d",&x1,&y1,&x2,&y2);
	first->xf=x1;
	first->yf=y1;
	first->xl=x2;
	first->yl=y2;
	for (i=1;i<sum;i++)
	{
		scanf ("%d%d%d%d",&x1,&y1,&x2,&y2);
		p->link=(struct dot *)malloc(sizeof(struct dot));
		p=p->link;
		p->xf=x1;
		p->yf=y1;
		p->xl=x2;
		p->yl=y2;
	}
	p->link=NULL;
	
//	for (q=first;q!=NULL;q=q->link)
//		printf ("%d %d %d %d\n",q->xf,q->yf,q->xl,q->yl);
	for (q=first;q!=NULL;q=q->link)
	{	
		s=q;
		while (s!=NULL)
		{
			for (r=first;r!=NULL;r=r->link)
			{
				if ((s->xl==r->xf)&&(s->yl==r->yf))
				{
					cnt++;
					s=r;
					break;
				}
			}
			if (r==NULL)
				break;
		}
		if (cnt>max)
		{
			max=cnt;
			result=q;
		}
		cnt=1;
	}
	
	printf ("%d %d %d",max,result->xf,result->yf);
	return 0;
}
