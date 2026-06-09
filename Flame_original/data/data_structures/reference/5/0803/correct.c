#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct node
{
    int coef;
    int exp;
    struct node *link;
}PNode,*PLinklist;
PLinklist read();
PLinklist cheng(PLinklist A, PLinklist B);
void attach(int co, int ex, PLinklist *r);
void output(PLinklist p);
int main()
{
    PLinklist A=read(),B=read();
    PLinklist b = cheng(A, B);
   	output(b);
    return 0;
}
void attach(int co, int ex, PLinklist *r)
{
	PLinklist w;
	w=(PLinklist)malloc(sizeof(PNode)); 
	w->coef = co;
	w->exp = ex;
	w->link = NULL;
	(*r)->link = w;
	*r = w;  
}
void output(PLinklist p)
{
	while(p!=NULL)
	{
		printf("%d %d ",p->coef, p->exp);
		p=p->link;		
	}
} 
PLinklist read()
{
	int co,ex;char a;
	PLinklist p, r, q;
	p = (PLinklist)malloc(sizeof(PNode)); 
	p->link = NULL;
	r=p; 
	while(1) 
	{
		scanf(" %d %d%c",&co,&ex,&a);
		attach(co, ex, &r);
		if(a!=' ') break;
	}
	q=p; 
	p=p->link;
	free(q);
	return p; 
}
PLinklist cheng(PLinklist A, PLinklist B)
{
	PLinklist p=A,q=B,r,s;
	PLinklist t=(PLinklist)malloc(sizeof(PNode));
	t->link = NULL;
	r = t;
	while(q!=NULL)
	{
		int co = p->coef * q->coef,ex = p->exp + q->exp;
		attach(co, ex, &r);
		q=q->link;
	}
	p=p->link;
	while(p!=NULL)
	{
		r=t , q=B;
		while(q)
		{
			int co = p->coef * q->coef,ex = p->exp + q->exp;
			while(r->link!=NULL&&r->link->exp>ex)	r=r->link;
			if(r->link!=NULL&&r->link->exp==ex)
			{
				if((co+r->link->coef)!=0)
				{
					r->link->coef += co;	
					r=r->link;
				} 
				else
				{
					s=r->link;
					r->link=s->link;
					free(s);
				} 
			}
			else
			{
				s=(PLinklist)malloc(sizeof(PNode));
				s->coef=co;
				s->exp=ex;
				s->link=r->link;
				r->link=s;
				r=r->link;
			}
			q=q->link;
		} 
		p=p->link;
	}
	s=t; 
	t=t->link;
	free(s);
	return t; 
} 

