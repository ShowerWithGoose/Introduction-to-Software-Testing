#include<stdio.h>
#include<stdlib.h>
typedef struct d{
	int a;
	int ceng;
	struct d *lchild;
	struct d *rchild;
}node;
void qxbianli(node *l);
int main()
{
	node *head=NULL;node *p=NULL;node *r=NULL;
	int n;scanf("%d",&n);
	while(n>0)
	{
		int d;
		scanf("%d",&d);
		p=(node*)malloc(sizeof(node));
		p->a=d;
		p->lchild=NULL;
		p->rchild=NULL;
		if(head==NULL) {
			p->ceng=1;
			head=p;
		}
		else
		{
			int w=2;
		    while(1)
		    {
		    	if(r->a>p->a)
		    	{
			    	if(r->lchild==NULL)
			    	{
			     		p->ceng=w;r->lchild=p;break;
			    	}
			    	else r=r->lchild;
		    	} 
		    	else
		    	{
		      		if(r->rchild==NULL)
			    	{
			    		p->ceng=w;r->rchild=p;break;
			    	}
			    	else r=r->rchild;
			    }
			    w++;
		    }
		}
		r=head;
		n--;
	}
	qxbianli(head);
} 
void qxbianli(node *l)
{
	if(l!=NULL){
		qxbianli(l->lchild);
		qxbianli(l->rchild);
		if(l->lchild==NULL&&l->rchild==NULL)
	    {
	    	printf("%d %d\n",l->a,l->ceng);
    	}
	}
} 

