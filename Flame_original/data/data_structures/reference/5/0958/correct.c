#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct dxs{
	int an,ex;
	struct dxs *link;
};
void destroylist(struct dxs* list);
void insertlist(struct dxs* q,struct dxs* head);
int main()
{
	char ch;
	int i,j,a,x;
	struct dxs *list[2],*head,*p,*q=NULL,*l1,*l2;
	for(j=0;j<2;j++)
	{
		scanf("%d%d%c",&a,&x,&ch);
		list[j]=malloc(sizeof(struct dxs));				
		p=list[j];
		p->an =a;
		p->ex =x;
		p->link =NULL;
		while(ch!='\n')
		{
			scanf("%d%d%c",&a,&x,&ch);
			p->link =malloc(sizeof(struct dxs));
			p=p->link ;
			p->an =a;
			p->ex =x;
			p->link =NULL;
		}
	}
	for(i=0,l1=list[0];l1!=NULL;l1=l1->link )
	{
		for(l2=list[1];l2!=NULL;l2=l2->link ,i++)
		{
			q=malloc(sizeof(struct dxs));
			q->an =(l1->an )*(l2->an );
			q->ex =(l1->ex )+(l2->ex );
			q->link =NULL;
			if(i==0)
			{
				head=q;
			}
			else
			{
				insertlist(q,head);
			}	
		}
	}
	for(p=head;p!=NULL;p=p->link )
	{
		if(p->an !=0)
		{
			printf("%d %d ",p->an ,p->ex );
		}
	}	
	destroylist(head);
	destroylist(list[0]);
	destroylist(list[1]);
	return 0;
}
void destroylist(struct dxs* list)
{
	if(list->link ==NULL)
	{
		free(list);
	}
	else
	{
		destroylist(list->link );
		free(list);
	}
}
void insertlist(struct dxs* q,struct dxs* head)
{
	struct dxs *p=head->link ,*r=head;
	for(;p!=NULL&&q->ex <p->ex ;r=p,p=p->link )
	{
		;
	}
	if(p==NULL)
	{
		r->link =q;
	}
	else if(q->ex ==p->ex )
	{
		p->an +=q->an ;
		free(q);
	}
	else
	{
		q->link =p;
		r->link =q;
	}
}

