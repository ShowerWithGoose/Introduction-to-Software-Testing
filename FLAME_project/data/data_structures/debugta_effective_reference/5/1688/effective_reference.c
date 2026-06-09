#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int a;
    int b;
    struct node *next;
}* Node;

Node newnode()
{
	Node p;
	p=malloc(sizeof(struct node));
	p->a=-1;
	p->b=-1;
	p->next=NULL;
	return p;
}

Node insert(Node p,int c,int x)
{
	Node link_hold;
	link_hold=p;
	Node temp;
	if(p->a==-1)
	{
		p->a=c;
		p->b=x;
		return p;
	}
	while(1)
	{
		if(link_hold->a>c)
		{
			if(link_hold->next==NULL)
			{
				Node p=newnode();
				link_hold->next=p;
				p->a=c;
				p->b=x;
				return p;
			}
			if(link_hold->next->a > c)
			{
				link_hold=link_hold->next;
			}
			else if(link_hold->next->a==c)
			{
				link_hold->next->b=link_hold->next->b+x;
				/*
				if(cur->next->xs==0)
				{
					temp=cur->next;
					cur->next=cur->next->next;
					free(temp);
				}*/
				return p;
			}
			else
			{
				Node p=newnode();
				p->next=link_hold->next;
				p->a=c;
				p->b=x;
				link_hold->next=p;
				return p;
			}
		}
		else if(link_hold->a==c)
		{
			link_hold->b=link_hold->b+x;
			/*
			if(cur->xs==0)
			{
				cur=cur->next;
				free(p);
				return cur;
			}*/
			return p;
		}/*
		else
		{
			Node n=newnode();
			n->next=cur;
			n->cs=c;
			n->xs=x;
			return n;
		}*/
	}
 } 

void freenode(Node p)
{
	if(p->next!=NULL)
	{
		freenode(p->next);
	}
	free(p);
}


int main()
{
	Node x1,x2,head_link;
	x1=newnode();
	x2=newnode();
	head_link=newnode();
	x1->a=-1;
	x2->a=-1;
	int c,x;
	char f=' ';
	while(f!='\n')
	{ 
		scanf("%d %d%c",&x,&c,&f);
		x1=insert(x1,c,x);
	}
	f=' ';
	while(f!='\n')
	{ 
		scanf("%d %d%c",&x,&c,&f);
		x2=insert(x2,c,x);
	}
	Node i,j;
	i=x1;
	j=x2;
	head_link->a=-1;
	while(i->next!=NULL)
	{
		j=x2;
		while(j->next!=NULL)
		{
			head_link=insert(head_link,i->a+j->a,i->b*j->b);
			j=j->next;
		}
		head_link=insert(head_link,i->a+j->a,i->b*j->b);
		i=i->next;
	}
	j=x2;
	while(j->next!=NULL)
	{
		head_link=insert(head_link,i->a+j->a,i->b*j->b);
		j=j->next;
	}
	head_link=insert(head_link,i->a+j->a,i->b*j->b);
	int qm=0;
	while(head_link->next!=NULL)
	{
		
		printf("%d %d ",head_link->b,head_link->a);
		head_link=head_link->next;
		qm++;
	}
	printf("%d %d",head_link->b,head_link->a);
	freenode(x1);
	freenode(x2);
	freenode(head_link);
	return 0;
}

