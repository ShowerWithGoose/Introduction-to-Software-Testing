#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct xy{
	int c;
	int n;
	struct xy *next;
}*xx,*yy,*s,*p,*q,*pp,*ppp,*tmp;

int main()
{
	char ch[1000]="";
	int i=0,j=0;
	int flag=1,num=0;
	gets(ch);
	p=malloc(sizeof(struct xy));
	xx=p;
	while(1)
	{
		if(ch[i]==' '||ch[i]=='\0')
		{
			if(flag==1)
			{
				p->c=num;
				flag=2;
			}
			else
			{
				p->n=num;
				flag=1;
				q=malloc(sizeof(struct xy));
				p->next=q;
				p=q;
			}
			num=0;
		}
		else
		num=num*10+ch[i]-'0';
		if(ch[i]=='\0') break;
		i++;
	}
	p->next=NULL;
	gets(ch);
	p=malloc(sizeof(struct xy));
	yy=p;
	i=0;
	while(1)
	{
		if(ch[i]==' '||ch[i]=='\0')
		{
			if(flag==1)
			{
				p->c=num;
				flag=2;
			}
			else
			{
				p->n=num;
				flag=1;
				q=malloc(sizeof(struct xy));
				p->next=q;
				p=q;
			}
			num=0;
		}
		else
		num=num*10+ch[i]-'0';
		if(ch[i]=='\0') break;
		i++;
	}
	p->next=NULL;
	p=xx;
	pp=malloc(sizeof(struct xy));
	s=malloc(sizeof(struct xy));
	ppp=malloc(sizeof(struct xy));
	s->c=0;
	s->n=0;
	s->next=NULL;
	while(p->next!=NULL)
	{
		pp=yy;
		ppp=s;
		while(pp->next!=NULL)
		{
			tmp=malloc(sizeof(struct xy));
			tmp->n=p->n+pp->n;
			tmp->c=p->c*pp->c;
			while(tmp->n<ppp->n)
			{
				if(ppp->next==NULL)
				{
					q=malloc(sizeof(struct xy));
					q->n=tmp->n;
					q->c=0;
					q->next=NULL;
					ppp->next=q;
					ppp=q;
					break;
				}
				ppp=ppp->next;
			}
			if(tmp->n>ppp->n)
			{
				q=malloc(sizeof(struct xy));
				q->c=ppp->c;
				q->n=ppp->n;
				q->next=ppp->next;
				ppp->next=q;
				ppp->c=tmp->c;
				ppp->n=tmp->n;
				ppp=q;
			}
			else
			{
				ppp->c+=tmp->c;
			}
			pp=pp->next;
		}
		p=p->next;
	}
	p=s;
	while(p->next!=NULL)
	{
		if(p->c!=0) 
		printf("%d %d ",p->c,p->n);
		p=p->next;
	}
	if(p->c!=0)
	{
		printf("%d %d ",p->c,p->n);
	}
//	printf("\n");
/*	
	p=xx;
	while(p->next!=NULL)
	{
		printf("%d %d ",p->c,p->n);
		p=p->next;
	}
	printf("\n");
	p=yy;
	while(p->next!=NULL)
	{
		printf("%d %d ",p->c,p->n);
		p=p->next;
	}
	printf("\n");*/
	return 0;
} 

