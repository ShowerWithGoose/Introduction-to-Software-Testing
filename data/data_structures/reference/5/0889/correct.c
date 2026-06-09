#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct multi{
	int auti;
	int exp;
	struct multi *link;
}LNode,*LinkList;
LinkList CEART()
{
	LinkList list=NULL,p,r;
	int a,b=1;
	char c='0';
	do{
		scanf("%d%d%c",&a,&b,&c);
		p=(LinkList)malloc(sizeof(LNode));
		p->auti=a;
		p->exp=b;
		if(list==NULL)
		{
			list=p;
		}
		else
		{
			r->link=p;
		}
		r=p;
	}while(c!='\n');
	r->link=NULL;
	return list;
}
int main()
{
	LinkList lista,listb,p,q,r=NULL,r1,listc=NULL;
	lista=CEART();
	listb=CEART();
	p=lista;
	q=listb;
	while(q!=NULL)
	{
		if(listc==NULL)
		{
			r=(LinkList)malloc(sizeof(LNode));
			r->auti=p->auti*q->auti;
			r->exp=p->exp+q->exp;
			listc=r;
		}
		else
		{
			r1=(LinkList)malloc(sizeof(LNode));
			r1->auti=p->auti*q->auti;
			r1->exp=p->exp+q->exp;
			r->link=r1;
			r=r1;
		}
		q=q->link;
	}
	r->link=NULL;
	p=p->link;
	while(p!=NULL)
	{
		q=listb;
		while(q!=NULL)
		{
			r1=(LinkList)malloc(sizeof(LNode));
			r1->auti=p->auti*q->auti;
			r1->exp=p->exp+q->exp;
			r=listc;
			while(r->link!=NULL&&(r->link->exp)>(r1->exp))
			r=r->link;
			if(r->link==NULL)
			{
				r->link=r1;
				r1->link=NULL;
			}
			else if(r->link->exp==r1->exp)
			{
				r->link->auti+=r1->auti;
			}
			else
			{
				r1->link=r->link;
				r->link=r1;
			}
			q=q->link;
		}
		p=p->link;
	}
	while(listc!=NULL&&listc->auti!=0)
	{
		printf("%d %d ",listc->auti,listc->exp);
		listc=listc->link;
	}
 	return 0;
}


