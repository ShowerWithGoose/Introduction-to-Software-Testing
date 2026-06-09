#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int epx;
	int ix;
	struct node *next;
}*List;
void del(List q)
{
	List t;
	t=q->next;
	q->next=t->next;
	free(t);
}
void insert(List head,List p)
{
	List L=head,q=head;
	if(L==NULL) L=p;
	while(L!=NULL)
	{
		if(L->epx==p->epx)
		{
			L->ix = L->ix + p->ix;
			if(L->ix==0)
			del(q);
			break;
		}
		else if(L->epx>p->epx&&L->next==NULL)
		{
			L->next=p;
			break;
		}
		else if(L->epx > p->epx&&L->next->epx<p->epx)
		{
			p->next=L->next;
			L->next=p;
			break;
		}
		else 
		{
			q=L; 
			L=L->next;
		}
	}
	return head;
 } 
int main()
{
	char x;
	List h1=NULL,h2=NULL,h3=NULL,p=NULL,q=NULL,t=NULL;
	while(1)
	{
		p=(List)malloc(sizeof(struct node));
		p->next=NULL;
		scanf("%d%d",&p->ix,&p->epx);
		if(h1==NULL)
		{
			h1=p;
			q=p;
		}
		else
		{
			q->next=p;
			q=p;
		}
		scanf("%c",&x);
		if(x=='\n')
		break;
	} 
/*	p=h1;
	while(p!=NULL)
	{
		printf("%d %d\n",p->ix,p->epx);
		p=p->next;
	}*/
	p=(List)malloc(sizeof(struct node));
	p->next=NULL;
	while(~scanf("%d%d",&p->ix,&p->epx))
	{
		if(h2==NULL)
		{
			h2=p;
			q=p;
		}
		else
		{
			q->next=p;
			q=p;
		}
		p=(List)malloc(sizeof(struct node));
		p->next=NULL;
	} 
/*	p=h2;
	while(p!=NULL)
	{
		printf("%d %d\n",p->ix,p->epx);
		p=p->next;
	}*/
	q=h1;
	while(q!=NULL)
	{
		p=h2;
		while(p!=NULL)
		{
			t=(List)malloc(sizeof(struct node));
			t->next=NULL;
			t->epx=q->epx + p->epx;
			t->ix=q->ix * p->ix;
			if(h3==NULL)
			h3=t;
			else
			insert(h3,t);
			p=p->next;
		}
		q=q->next;
	 } 
	p=h3;
	while(p!=NULL)
	{
		printf("%d %d ",p->ix,p->epx);
		p=p->next;
	}
	
	return 0;
}

