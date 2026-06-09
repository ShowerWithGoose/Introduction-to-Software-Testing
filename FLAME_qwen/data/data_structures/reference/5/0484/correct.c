#include<stdio.h>
#include<stdlib.h>
struct node{
	
	int coef;
	int exp;
	struct node*next;
};

struct node*Multi()
{
	char c; 
	int flag=0;
	int temp; 
	struct node*lista=NULL,*listb=NULL,*listc=NULL,*p,*q,*r,*t,*s;
	int co,index;
	while(1)//创建链表a 
	{
		p=(struct node*)malloc(sizeof(struct node));
		scanf("%d%d",&p->coef,&p->exp);
		if(lista==NULL)
		{
			lista=p;
		}
		else
		{
			q->next=p;
		}
		q=p;
		c=getchar();
		if(c=='\n')
		  break;
	}
	p->next=NULL;

	while(1)//创建链表b 
	{
		p=(struct node*)malloc(sizeof(struct node));
		scanf("%d%d",&p->coef,&p->exp);
		if(listb==NULL)
		{
			listb=p;
		}
		else
		{
			q->next=p;
		}
		q=p;
		c=getchar();
		if(c=='\n')
		  break;
	}
	p->next=NULL;
	
	p=lista,q=listb;//p，q分别指向a，b开头 
	
	while(p!=NULL)
	{
		r=(struct node*)malloc(sizeof(struct node));
		r->coef=(p->coef)*(q->coef);
		r->exp=p->exp+q->exp;
		s=listc;
		while(s!=NULL)
		{
			if(s->exp==r->exp)//找到exp一样的 
			{
				s->coef+=r->coef;
				flag=1;
				free(r);
				break;
			}
			s=s->next;
		}
		if(flag)
		{
			if(q->next!=NULL)
			{
				q=q->next;
			}
			else
			{
				p=p->next;
				q=listb;
			}
			flag=0;
			continue;
		}
	
		if(listc==NULL)
		{
			listc=r;
			listc->next=NULL;
		}
		else
		{
			t->next=r;
			r->next=NULL;
		} 
		t=r;
		if(q->next!=NULL)
		{
			q=q->next;
		}
		else
		{
			p=p->next;
			q=listb;
		}
	}
	
	for(p=listc;p->next!=NULL;p=p->next)
	{
		for(q=listc;q->next!=NULL;q=q->next)
		{
			if(q->exp<q->next->exp)
			{
				temp=q->exp;
				q->exp=q->next->exp;
				q->next->exp=temp;
				
				temp=q->coef;
				q->coef=q->next->coef;
				q->next->coef=temp;
			}
		}
	}

	return listc;
	 
}
int main()
{
	struct node*list;
	list=Multi();
	while(list!=NULL)
	{
		printf("%d %d ",list->coef,list->exp);
		list=list->next;
	}
	return 0;
}

