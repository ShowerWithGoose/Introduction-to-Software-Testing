#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	int a;
	int n;
	struct node *link;
} *list1=NULL,*list2=NULL,*list3=NULL,*p,*q,*r,*n,*m;

int main()
{
	char c;
	int i,j;
	do {
		p=(struct node*)malloc(sizeof(struct node));
		p->link=NULL;
		scanf("%d%d%c",&p->a,&p->n,&c);
		if(list1==NULL)
		{
			list1=q=p;
		} else{
			q->link=p;
			q=p;
		}
		
	} while(c!='\n');
	
	do {
		p=(struct node*)malloc(sizeof(struct node));
		p->link=NULL;
		scanf("%d%d%c",&p->a,&p->n,&c);
		if(list2==NULL)
		{
			list2=q=p;
		} else{
			q->link=p;
			q=p;
		}
		
	} while(c!='\n');
	for(p=list1;p!=NULL;p=p->link)
	{
		for(q=list2;q!=NULL;q=q->link)
		{
			r=(struct node*)malloc(sizeof(struct node));
			r->a=(p->a*q->a);
			r->n=p->n+q->n;
			r->link=NULL;
			if(list3==NULL)
			{
				list3=m=r;
			}else {
				for(n=list3;n!=NULL;m=n,n=n->link)
				{
					if(n->n<r->n)
					{
						if(n==list3)
						{
							list3=r;
							r->link=n;
							break;
						} else{
							m->link=r;
							r->link=n;
							break;
						}
					} else if(n->n==r->n)
					{
						n->a=n->a+r->a;
						break;
					}
				}
				if(n==NULL)
				{
					m->link=r;
				}
			}
			
		}
	}
	for(p=list3;p!=NULL;p=p->link)
	{
		printf("%d %d ",p->a,p->n);
	}
	
}
















