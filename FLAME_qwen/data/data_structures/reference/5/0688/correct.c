#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int cs;
    int xs;
    struct node *next;
}* Node;

Node newnode()
{
	Node p;
	p=malloc(sizeof(struct node));
	p->cs=-1;
	p->xs=-1;
	p->next=NULL;
	return p;
}

Node insert(Node p,int c,int x)
{
	Node cur;
	cur=p;
	Node temp;
	if(p->cs==-1)
	{
		p->cs=c;
		p->xs=x;
		return p;
	}
	while(1)
	{
		if(cur->cs>c)
		{
			if(cur->next==NULL)
			{
				Node n=newnode();
				cur->next=n;
				n->cs=c;
				n->xs=x;
				return p;
			}
			if(cur->next->cs > c)
			{
				cur=cur->next;
			}
			else if(cur->next->cs==c)
			{
				cur->next->xs=cur->next->xs+x;
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
				Node n=newnode();
				n->next=cur->next;
				n->cs=c;
				n->xs=x;
				cur->next=n;
				return p;
			}
		}
		else if(cur->cs==c)
		{
			cur->xs=cur->xs+x;
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
	Node x1,x2,m;
	x1=newnode();
	x2=newnode();
	m=newnode();
	x1->cs=-1;
	x2->cs=-1;
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
	Node l1,l2;
	l1=x1;
	l2=x2;
	m->cs=-1;
	while(l1->next!=NULL)
	{
		l2=x2;
		while(l2->next!=NULL)
		{
			m=insert(m,l1->cs+l2->cs,l1->xs*l2->xs);
			l2=l2->next;
		}
		m=insert(m,l1->cs+l2->cs,l1->xs*l2->xs);
		l1=l1->next;
	}
	l2=x2;
	while(l2->next!=NULL)
	{
		m=insert(m,l1->cs+l2->cs,l1->xs*l2->xs);
		l2=l2->next;
	}
	m=insert(m,l1->cs+l2->cs,l1->xs*l2->xs);
	int qm=0;
	while(m->next!=NULL)
	{
		
		printf("%d %d ",m->xs,m->cs);
		m=m->next;
		qm++;
	}
	printf("%d %d",m->xs,m->cs);
	freenode(x1);
	freenode(x2);
	freenode(m);
	return 0;
}

