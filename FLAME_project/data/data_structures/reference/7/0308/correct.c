#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	int height;
	struct node *l,*r;
}BTNode,*BTNodeptr;
void cha(BTNodeptr t)
{
	if(t!=NULL)
	{
		cha(t->l);
		cha(t->r);
	}
	if(t==NULL)
		return ;
	if(t->r==NULL&&t->l==NULL)
		printf("%d %d\n",t->data,t->height);
}
BTNodeptr insert(BTNodeptr p,int item,int dep)
{
	if(p==NULL)
	{
		p=(BTNodeptr)malloc(sizeof(BTNode));
		p->data=item;
		p->l=NULL;
		p->r=NULL;
		p->height=dep;
	}
	else if(item<p->data)
	{
		p->l=insert(p->l,item,dep+1);
	}
	else if(item>=p->data)
	{
		p->r=insert(p->r,item,dep+1);
	}
	return p;
}
BTNodeptr root=NULL;
int main()
{
	int i,item,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&item);
		root=insert(root,item,1);
	}
	cha(root);
	return 0;
} 

