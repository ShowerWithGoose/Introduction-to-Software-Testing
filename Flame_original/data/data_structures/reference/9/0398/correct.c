#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct loca
{
	int x,y;
};
struct node
{
	struct loca start,end;
	struct node* line_link,*link;
};
void find(struct node*q,struct node*list)
{
	struct node*u;
	for(u=list;u!=NULL;u=u->link)
	{
		if((q->end).x==(u->start).x&&(q->end).y==(u->start).y)
		{
			q->line_link=u;
			if(u->line_link==NULL)
				find(u,list);
			return ;
		}
	}
}
int main()
{
	int n,i,j,max=0;
	struct node*list=NULL,*p,*q,*ans;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		q=(struct node*)malloc(sizeof(struct node));
		scanf("%d%d%d%d",&((q->start).x),&((q->start).y),&((q->end).x),&((q->end).y));
		q->line_link=NULL;q->link=NULL;
		if(list==NULL)
			list=q;
		else
			p->link=q;
		p=q;
	}
	for(p=list;p!=NULL;p=p->link)
		if(p->line_link==NULL)
			find(p,list);
	for(p=list;p!=NULL;p=p->link)
	{
		for(j=0,q=p;q!=NULL;q=q->line_link,j++);
		if(j>max)
		{
			max=j;ans=p;
		}
	}
	printf("%d %d %d",max,(ans->start).x,(ans->start).y);
	return 0;
}

