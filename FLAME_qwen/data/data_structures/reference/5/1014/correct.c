#include<stdio.h>
#include<stdlib.h>
struct pol{
	int x;
	int y;
	struct pol *link;
};
int main()
{
	struct pol *firstA=NULL,*firstB=NULL,*tailA=NULL,*tailB=NULL,*p=NULL,*q=NULL,*firstC=NULL,*tailC=NULL,*r=NULL,*fre=NULL;
	char a,b;
	int temp;
	do 
	{
		q=(struct pol *)malloc(sizeof(struct pol));
		q->link=NULL;
		if(firstA==NULL)
			tailA=firstA=q;
		else
		{
			tailA->link=q;
			tailA=q;
		}
		scanf("%d%c%d%c",&q->x,&a,&q->y,&b);
	}while(b!='\n');
	do 
	{
		p=(struct pol *)malloc(sizeof(struct pol));
		p->link=NULL;
		if(firstB==NULL)
			tailB=firstB=p;
		else
		{
			tailB->link=p;
			tailB=p;
		}
		scanf("%d%c%d%c",&p->x,&a,&p->y,&b);
	}while(b!='\n');
	q=firstA;
	p=firstB;
	for(;q!=NULL;)
	{
		for(;p!=NULL;)
		{
			r=(struct pol *)malloc(sizeof(struct pol));
			r->x=p->x*q->x;
			r->y=p->y+q->y;
			r->link=NULL;
			if(firstC==NULL)
				tailC=firstC=r;
			else
			{
				tailC->link=r;
				tailC=r;
			}
			if(q->link==NULL)
			{
				fre=p;
				p=p->link;
				free(fre);
			}
			else
				p=p->link;
		}
		fre=q;
		q=q->link;
		free(fre);
		p=firstB;
	}
	r=firstC;
	p=r;
	q=r->link;
	for(;p!=NULL;)
	{
		for(;q!=NULL;)
		{
			if(r->y==q->y)
			{
				r->x=r->x+q->x;
				p->link=q->link;
				fre=q;
				q=q->link;
				free(fre);
			}
			else
			{
				p=p->link;
				q=q->link;
			}
		}
		r=r->link;
		p=r;
		if(r!=NULL)
			q=r->link;
	}
	p=firstC;
	q=p->link;
	while((p->link)!=NULL)
	{
		r=p;
		while(q!=NULL)
		{
			if(r->y<q->y)
				r=q;	
			q=q->link;
		}
		temp=p->x;
		p->x=r->x;
		r->x=temp;
		temp=p->y;
		p->y=r->y;
		r->y=temp;
		p=p->link;
		q=p->link;
	}
	r=firstC;
	for(;r!=NULL;)
	{
		printf("%d %d ",r->x,r->y);
		fre=r;
		r=r->link;
		free(fre);
	}
	return 0;
}

