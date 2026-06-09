/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct node
{
	int coef;
	int index;
	struct node *link;
}LNode,*Link;

int main()
{
	int num1,num2;
	char s1[10000],s2[10000],*poi;
	Link list1,r1,list2,r2;
	gets(s1);
	gets(s2);
	
	//读入两多项式 
	{
		
	{
		poi=s1;
	num1=atoi(poi);
	while(isdigit(*poi))
		poi++;
	poi++;
	num2=atoi(poi);
	while(isdigit(*poi))
		poi++;
		
	
	Link p=(Link)malloc(sizeof(LNode));
	p->coef=num1;
	p->index=num2;
	list1=p;
	r1=p;
	r1->link =NULL;

	if(poi!=NULL)
	while(poi!=NULL)
	{
		poi++;
		num1=atoi(poi);
		if(num1==0) break;
		while(isdigit(*poi))
			poi++;
		poi++;
		num2=atoi(poi);
		while(isdigit(*poi))
			poi++;
		
		Link p=(Link)malloc(sizeof(LNode));
		p->coef =num1;
		p->index =num2;
		r1->link =p;
		r1=p;
		r1->link =NULL;
	}

	}
	
	{
	poi=s2;
	num1=atoi(poi);
	while(isdigit(*poi))
		poi++;
	poi++;
	num2=atoi(poi);
	while(isdigit(*poi))
		poi++;
		
	
	Link p=(Link)malloc(sizeof(LNode));
	p->coef=num1;
	p->index=num2;
	list2=p;
	r2=p;
	r2->link =NULL;
	
	if(poi!=NULL)
	while(poi!=NULL)
	{
		poi++;
		num1=atoi(poi);
		if(num1==0) break;
		while(isdigit(*poi))
			poi++;
		poi++;
		num2=atoi(poi);
		while(isdigit(*poi))
			poi++;
		
		Link p=(Link)malloc(sizeof(LNode));
		p->coef =num1;
		p->index =num2;
		r2->link =p;
		r2=p;
		r2->link =NULL;
	}
	}
	
	}
	
	Link p,q,list,r;
	p=list1;
	q=list2;
	
	Link pos=(Link)malloc(sizeof(LNode));
	pos->coef =p->coef*q->coef;
	pos->index=p->index+q->index;
	
	list=pos;
	r=pos;
	r->link =NULL;
	
	q=q->link ;

	//printf("%d %d ",pos->coef ,pos->index );
	
	while(p!=NULL)
	{
		while(q!=NULL)
		{
			Link pos=(Link)malloc(sizeof(LNode));
			pos->coef=p->coef*q->coef;
			pos->index=p->index+q->index;
			
			//printf("%d %d ",pos->coef ,pos->index );
			
			r->link =pos;
			r=pos;
			r->link =NULL; 
			
			q=q->link ;
		}
		q=list2;
		p=p->link ;
	}
	
	p=list;

	while(p!=r)
	{
		q=p;
		while(q!=r)
		{
			if(p->index==q->link->index)
			{
				p->coef+=q->link->coef;
				if(q->link!=r)
					q->link =q->link->link;
				else
				{
					q->link=NULL;
					r=q;
				}
			}
			q=q->link;
		}
		p=p->link;
	}
	
	p=list;
	while(p!=r)
	{
		q=p;
		while(q!=r)
		{
			if(p->index<q->link->index)
			{
				int a1=0,a2=0;
				a1=p->coef;
				a2=p->index;
				p->coef =q->link->coef;
				p->index=q->link->index;
				q->link->coef=a1;
				q->link->index =a2;
			}
			q=q->link;
		}
		p=p->link;
	}
	
	p=list;
	while(p->link!=NULL)
	{
		printf("%d %d ",p->coef ,p->index );
		p=p->link;
	}
	printf("%d %d",r->coef,r->index);
	
	return 0; 
}

