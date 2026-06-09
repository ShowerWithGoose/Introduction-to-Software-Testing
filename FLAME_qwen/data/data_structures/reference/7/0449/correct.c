#include <stdio.h>
#include <stdlib.h>
int high=0;

struct node{
	int data;
	int h;
	struct node *lc,*rc;
};

typedef struct node Node;
typedef struct node *Nodeptr;

Nodeptr insert(Nodeptr p, int x)
{
	high++;
	if(NULL==p)
	{
		
		p=(Nodeptr)malloc(sizeof(Nodeptr));
		p->data=x;
		p->lc=NULL;
		p->rc=NULL;
		p->h=high;
	}
	else if(x>=p->data)
	{
		p->rc=insert(p->rc,x);
	}
	else if(x<p->data)
	{
		p->lc=insert(p->lc,x);
	}
	
	return p;
}

void output(Nodeptr p)
{
	if(p!=NULL)
	{
		if((p->lc==NULL)&&(p->rc==NULL))
		{
			printf("%d %d\n",p->data,p->h);
		}
		output(p->lc);
		output(p->rc);
	}
	
}

int main()
{
	int n;
	scanf("%d",&n);
	int i=0;
	int num;
	Nodeptr root=NULL;
	for(i=0;i<n;i++)
	{
		high=0;
		scanf("%d",&num);
		root=insert(root,num);
	}
	output(root);
	
	return 0;
	
 } 



