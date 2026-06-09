#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coef;
	int exp;
	struct node *link;
};
struct node* build()
{
	struct node *list;
	list=(struct node*)malloc(sizeof(struct node));
	list->link=NULL;
	return list;
}
struct node* insert(struct node*p)
{
	struct node *r;
	r=(struct node*)malloc(sizeof(struct node));
	r->link=p->link;
	p->link=r;
	return r;
}
struct node* delect(struct node*p,struct node*q)
{
	p->link=q->link;
	free(q);
	return p->link;
}
int main()
{
	struct node *tem,*p,*q,*r,*lista,*listb,*listc,*listd;
	char c;
	lista=build();
	listb=build();
	listc=build();
	listd=build();
	p=lista;
	do
	{
		scanf("%d%d",&(p->coef),&(p->exp));
		q=p;
		p=insert(p);	
	}while((c=getchar())!='\n');
	q->link=NULL;
	free(p);
	p=listb;
	do
	{
		scanf("%d%d",&(p->coef),&(p->exp));
		q=p;
		p=insert(p);	
	}while((c=getchar())!='\n');
	q->link=NULL;
	free(p);
	p=lista;
	q=listb;
	r=listc;
	tem=r;
	while(p!=NULL)
	{
		q=listb;
		while(q!=NULL)
		{
			r->coef =p->coef *q->coef;
			r->exp =p->exp+q->exp;
			tem=r; 
			r=insert(r);
			q=q->link;
		}
		p=p->link;
	}
	tem->link=NULL;
	free(r);
	r=listc;
	p=listd;
	p->coef=r->coef;
	p->exp=r->exp;
	p->link=NULL;
	r=r->link;
	while(r!=NULL)
	{
		q=listd;
		tem=q;
		while(q!=NULL&&r->exp <q->exp)
		{
			tem=q;
			q=q->link;
		}
		if(q==NULL||r->exp >q->exp)
		{
			tem=insert(tem);
			tem->coef =r->coef ;
			tem->exp =r->exp ;
		}
		else if(r->exp ==q->exp)
		{
			if(r->coef +q->coef==0)
			{
				q=delect(tem,q);
			}	
			else
			{
				q->coef=r->coef+q->coef;
			}
		}	
		r=r->link;
	}
	p=listd;
	while(p!=NULL)
	{
		printf("%d %d ",p->coef ,p->exp);
		p=p->link;
	}
	return 0;
}

