#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct f{
	long long a,n;
	struct f *next;
};
struct f *h1,*h2,*e,*p1,*q1,*r1,*z;

void read_l(char c[],struct f *h)
{
	struct f *r,*p=h;
	int i;
	for(i=0;c[i]!='\0';i++)
	{
		for(i=i;c[i]!=' ';i++)
		p->a=p->a*10+c[i]-'0';
		for(i+=1;c[i]!=' '&&c[i]!='\0';i++)
		p->n=p->n*10+c[i]-'0';
		r=p;
		p=(struct f *)malloc(sizeof(struct f));
		p->a=0;
		p->n=0;
		r->next=p;
		if(c[i]=='\0')
		break;
	}
	r->next=NULL;
	free(p);
}

int main()
{
	char c[10000];
	int a0,n0;
	gets(c);
	h1=(struct f *)malloc(sizeof(struct f));
	h1->a=0;
	h1->n=0;
	read_l(c,h1);
	gets(c);
	h2=(struct f *)malloc(sizeof(struct f));
	h2->a=0;
	h2->n=0;
	read_l(c,h2);
	e=(struct f *)malloc(sizeof(struct f));
	e->a=h1->a*h2->a;
	e->n=h1->n+h2->n;
	e->next=NULL;
	r1=h2->next;
	q1=e;
	while(r1!=NULL)
	{
		z=(struct f *)malloc(sizeof(struct f));
		z->a=h1->a*r1->a;
		z->n=h1->n+r1->n;
		r1=r1->next;
		q1->next=z;
		q1=z;
	}
	q1->next=NULL;
	z=h1;
	h1=h1->next;
	free(z);
	while(h1!=NULL)
	{
		q1=e;
		r1=h2;
		while(r1!=NULL)
		{
			a0=h1->a*r1->a;
			n0=h1->n+r1->n;
			while(q1!=NULL&&q1->n>n0)
			{
				p1=q1;
				q1=q1->next;
			}
			if(q1==NULL)
			{
				z=(struct f *)malloc(sizeof(struct f));
				z->a=a0;
				z->n=n0;
				z->next=NULL;
				p1->next=z;
				q1=z;
			}
			else if(q1->n==n0)
			q1->a+=a0;
			else
			{
				z=(struct f *)malloc(sizeof(struct f));
				z->next=q1;
				z->a=a0;
				z->n=n0;
				p1->next=z;
				p1=z;
			}
			r1=r1->next;
		}
		z=h1;
		h1=h1->next;
		free(z);
	}
	while(e->next!=NULL)
	{
	printf("%lld %lld ",e->a,e->n);
	z=e;
	e=e->next;
	free(z);
	}
	printf("%lld %lld",e->a,e->n);
	free(e);
	return 0;
} 

