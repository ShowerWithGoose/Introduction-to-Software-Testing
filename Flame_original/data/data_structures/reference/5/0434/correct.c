#include <stdio.h>
#include <stdlib.h>

struct mul
{
	int coe;
	int index;
	struct mul *link;
};

int main ()
{
	struct mul *first=NULL,*first1=NULL,*first2=NULL,*q,*p,*r,*s,*t;
	int flag=0,a,b;
	
	q=(struct mul *)malloc(sizeof(struct mul));
	first1=q;
	do{
		scanf ("%d%d",&a,&b);
		if (a!=0)
		{
			if (flag==0)
			{
				first1->coe=a;
				first1->index=b;
				q->link=(struct mul *)malloc(sizeof(struct mul));
				q=q->link;
				flag=1;
			}
			else
			{
				q->coe=a;
				q->index=b;
				q->link=(struct mul *)malloc(sizeof(struct mul));
				q=q->link;
			}	
		}
	}while(getchar()!='\n');
	q->link=NULL;
//	for (p=first1;p->link!=NULL;p=p->link)
//		printf ("%lld %lld ",p->coe,p->index);
	
	flag=0;
	q=(struct mul *)malloc(sizeof(struct mul));
	first2=q;
	do{
		scanf ("%d%d",&a,&b);
		if (a!=0)
		{
			if (flag==0)
			{
				first2->coe=a;
				first2->index=b;
				q->link=(struct mul *)malloc(sizeof(struct mul));
				q=q->link;
				flag=1;
			}
			else
			{
				q->coe=a;
				q->index=b;
				q->link=(struct mul *)malloc(sizeof(struct mul));
				q=q->link;
			}	
		}
	}while(getchar()!='\n');
	q->link=NULL;
//	for (p=first2;p->link!=NULL;p=p->link)
//		printf ("%lld %lld ",p->coe,p->index);
	
	flag=0;
	q=(struct mul *)malloc(sizeof(struct mul));
	first=q;
	for (p=first1;p->link!=NULL;p=p->link)
	{
		for (r=first2;r->link!=NULL;r=r->link)
		{
			if (flag==0)
			{
				first->coe=(p->coe)*(r->coe);
				first->index=(p->index)+(r->index);
				first->link=NULL;
				flag=1;
			}
			else
			{
				for (s=first;s!=NULL;t=s,s=s->link)
				{
					if (((p->index)+(r->index))>(s->index))
					{
						q=(struct mul *)malloc(sizeof(struct mul));
						if (s==first)
						{
							q->index=(p->index)+(r->index);
							q->coe=(p->coe)*(r->coe);
							q->link=first;
							first=q;
						}
						else
						{
							q->index=(p->index)+(r->index);
							q->coe=(p->coe)*(r->coe);
							t->link=q;
							q->link=s;
						}
						break;
					}
					else if (((p->index)+(r->index))==(s->index))
					{
						s->coe=s->coe+(p->coe)*(r->coe);
						break;
					}
				}
				if (s==NULL)
				{
					q=(struct mul *)malloc(sizeof(struct mul));
					q->index=(p->index)+(r->index);
					q->coe=(p->coe)*(r->coe);
					t->link=q;
					q->link=NULL;
				}
			}
		}
	}
	
	for (p=first;p!=NULL;p=p->link)
		printf ("%d %d ",p->coe,p->index);
	
	return 0;
}


