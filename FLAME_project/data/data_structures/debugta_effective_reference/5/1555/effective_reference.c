#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coe;
	int exp;
	struct node* next;
};
void settleresult(struct node* head,struct node* p);
int main()
{
	struct node* head1=(struct node*)malloc(sizeof(struct node)); 
	struct node* head2=(struct node*)malloc(sizeof(struct node));
	head1->next=NULL;
	head2->next=NULL;
	int a,b;
	char ch;
	struct node *p,*q;
	while(scanf("%d %d%c",&a,&b,&ch))
	{
		p=(struct node *)malloc(sizeof(struct node));
		p->coe=a;
		p->exp=b;
		if(head1->next==NULL)
		{
			head1->next=p;
		}
		else
		{
			q->next=p;
			p->next=NULL;
		}
		q=p;
		if(ch=='\n')
		break;
	}
	struct node *s,*t;
	while(scanf("%d %d%c",&a,&b,&ch))
	{
		s=(struct node *)malloc(sizeof(struct node));
		s->coe=a;
		s->exp=b;
		if(head2->next==NULL)
		{
			head2->next=s;
		}
		else
		{
			t->next=s;
			s->next=NULL;
		}
		t=s;
		if(ch=='\n')
		break;
	}
	p=head1->next;
	int m,n;
	struct node *head3=(struct node *)malloc(sizeof(struct node));
	head3->next=NULL;
	struct node *h;
	while(p)
	{
		s=head2->next;
		while(s)
		{
			h=(struct node *)malloc(sizeof(struct node));
			m=(p->coe)*(s->coe);
			n=p->exp+s->exp;
			h->coe=m;
			h->exp=n;
			settleresult(head3,h);
			s=s->next;
		}
		p=p->next;
	}
	h=head3->next;
	while(h)
	{
		printf("%d %d ",h->coe,h->exp);
		h=h->next;
	}
return 0;	
}
void settleresult(struct node* head,struct node* p)
{
	struct node *pf,*pb;
	if(head->next==NULL) 
	{
		head->next=p;
		p->next=NULL;
		return;
	}
	pf=head->next;
	pb=pf->next;
	if(head->next!=NULL)
	{
		if(pb==NULL)
		{
			if(p->exp>pf->exp)
			{
				head->next=p;
				p->next=pf;
			}
			else if(p->exp<pf->exp)
			{
				pf->next=p;
				p->next=NULL;
			}
			else
			{
				pf->coe=p->coe+pf->coe;
				free(p);
			}
		return;
		}
		else
		{
			if(p->exp>pf->exp)
			{
				head->next=p;
				p->next=pf;
			}
			else if(p->exp<pf->exp)
			{
				while(pb)
				{
					if(pb->exp>p->exp)
					{
						pf=pf->next;
						pb=pb->next;
						continue;	
					}
					if(pb->exp<p->exp)
					{
						pf->next=p;
						p->next=pb;
						return;
					}
					if(pb->exp=p->exp)
					{
						pb->coe=pb->coe+p->coe;
						free(p);
						return;
					}
				}
				pf->next=p;
				p->next=NULL;
			return;
			}
		 	else
		 	{
		 		pf->coe=pf->coe+p->coe;
				free(p);	
			}
		} 
	}
}

