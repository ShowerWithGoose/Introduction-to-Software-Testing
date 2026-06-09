#include<stdio.h>
#include<stdlib.h>

struct tree{
	int high;
	int number;
	struct tree* l;
	struct tree* r;
}*geng;


int  luru()
{
	struct tree *p,*q;
	int n;
	int height=1;
	p=geng;
	q=geng;
	
	scanf("%d",&n);
	while(1)
	{
		if(q==NULL) 
		{
			q=(struct tree*)malloc(sizeof(struct tree));
			q->high=height;
			q->number=n;
			q->l=NULL;
			q->r=NULL;
			
			if(n<(p->number)) p->l=q;
			else p->r=q;
			break;
		}
		height+=1;
		p=q;
		
		if(n<p->number) q=p->l;
		else if(n>=p->number) q=p->r;
	}
	
	return 0;
}


void destory(struct tree *q)
{
	if(q!=NULL)
	{
		destory(q->l);
		destory(q->r);
		free(q);
	}
}


int shuchu(struct tree* geng)
{
	struct tree * p=geng;
	
	if((p->l==NULL)&&p->r==NULL) printf("%d %d\n",p->number,p->high);
	if(p->l!=NULL) shuchu(p->l);
	if(p->r!=NULL) shuchu(p->r);
	
	return 0;
}


int main()
{
	int n;
	int root;
	
	scanf("%d",&n);
	scanf(" %d",&root);
	
	geng=(struct tree*)malloc(sizeof(struct tree));
	geng->high=1;
	geng->number=root;
	geng->l=NULL;
	geng->r=NULL;

	for(int i=1;i<n;i++) luru();
	
	shuchu(geng);
	
	destory(geng);
	
	return 0;
}

