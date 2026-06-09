//3_3
#include <stdio.h>
#include <stdlib.h>

struct multi
{
	int a;
	int n;
	struct multi *next;
};

int main(int argc, char const *argv[])
{
	struct multi *f1=NULL,*f2=NULL,*first=NULL,*p,*q,*r,*s;
	int a,n;
	char c;
	do
	{
		scanf("%d%d",&a,&n);
		q=(struct multi*)malloc(sizeof(struct multi));
		q->a=a;
		q->n=n;
		q->next=NULL;
		if(f1==NULL) f1=p=q;
		else p->next=q,p=p->next;
		c=getchar();
	}while(c==' ');
	while(scanf("%d%d",&a,&n)!=EOF)
	{
		q=(struct multi*)malloc(sizeof(struct multi));
		q->a=a;
		q->n=n;
		q->next=NULL;
		if(f2==NULL) f2=p=q;
		else p->next=q,p=p->next;
	}
	p=f1;
	while(p!=NULL)
	{
		q=f2;
		while(q!=NULL)
		{
			s=(struct multi*)malloc(sizeof(struct multi));
			s->a=p->a*q->a;
			s->n=p->n+q->n;
			s->next=NULL;
			if(first==NULL) first=s;
			else
			{
				r=first;
				if(r->n<s->n)
				{
					s->next=first;
					first=s;
					continue;
				}
				else if(r->n==s->n)
				{
					r->a+=s->a;
					continue;
				}
				while(r->next!=NULL)
				{
					if(r->next->n<s->n)
					{
						s->next=r->next;
						r->next=s;
						break;
					}
					else if(r->next->n==s->n)
					{
						r->next->a+=s->a;
						break;
					}
					r=r->next;
				}
				if(r->next==NULL) r->next=s;
			}
			q=q->next;
		}
		p=p->next;
	}
	p=first;
	while(p!=NULL) printf("%d %d ",p->a,p->n),p=p->next;
	return 0;
}
