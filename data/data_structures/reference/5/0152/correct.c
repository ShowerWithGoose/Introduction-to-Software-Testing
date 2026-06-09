
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int i;
struct node
{
	long long a;//系数 
	long long b;//指数 
	struct node* next; 
};

struct node getlist()//建链表 
{
	struct node *list=NULL,*p=NULL,*t=NULL;
	for(i=0;i<1000;i++)//找一个比较大的数，不知道项数是多少 
	{
		t=(struct node*)malloc(sizeof(struct node));
		scanf("%lld%lld",&t->a ,&t->b);
		if(getchar()=='\n')
		{
			if(i==0)
			{
				list=p=t;
				p->next= NULL;
				break;//特殊情况	
			}
				p->next=t;
				p=p->next;
				p->next=NULL;
				break;
		 }
			if(list==NULL)
			  {
				list=p=t;
				continue;
								
				}//指针为空
			else
			{
				p->next=t;
				p=p->next;
			 } 
		}
		

	return *list;	
}
void exchange(struct node*list) //排序交换 
{
	struct node* r,*m;
	r=list;//头
	m=NULL;//尾
	if(r==NULL||r->next==NULL)//链表为空或不用排序 
		return;
	while(r!=m)
	{
		while(r->next!=m)
		{
			if(r->b<r->next->b)//排序
			{
				long long temp,temp1;
				temp=r->b;
				r->b=r->next->b;
				r->next->b=temp;//指数换 
				temp1=r->a;
				r->a=r->next->a;
				r->next->a=temp1;//系数换 
			 } 
			r=r->next;
		}
		m=r;
		r=list;
	 } 
}
void result(struct node* x,struct node* y)
{
	struct node* list=NULL,*p=NULL,*t=NULL,*q,*w;
	for(q=x;q!=NULL;q=q->next)//第一个多项式 
	{
		for(w=y;w!=NULL;w=w->next)//第二个多项式 
		{
			t=(struct node*)malloc(sizeof(struct node));
			t->a=q->a*w->a;
			t->b=q->b+w->b;
			if(list==NULL)
			{
				list=p=t;
			}
			else
			{
				p->next=t;
				p=p->next;
			}
		}
	}
		p->next=NULL;
		for(p=list;p!=NULL;p=p->next)
		{
			struct node *p1=p,*p2=NULL;
			for(p2=p->next;p2!=NULL;p2=p2->next)
			{
				if(p2->b==p->b)
				{
					p->a+=p2->a;
					p1->next=p2->next;
					free(p2);
					p2=p1->next;
				}
				p1=p2;
			}
			
		}
		exchange(list);
		for(p=list;p!=NULL;p=p->next)
		{
			printf("%lld %lld ",p->a,p->b);
		}
		
	
}
int main()
{
	struct node o1,o2;
	o1=getlist();
	o2=getlist();
	result(&o1,&o2);
	return 0;	 
}


