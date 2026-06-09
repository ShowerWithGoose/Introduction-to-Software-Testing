#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
 	int data;
 	int height;
 	struct node *lchild,*rchild;
}node,*ptr;
ptr insert(ptr p,int item);
ptr search(ptr t);
int hold;
int main()
{
	int i=0,item;
	ptr root=NULL;
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&item);
		root=insert(root,item);
	}
	search(root);
	return 0;
}
ptr insert(ptr p,int item)
{
	if(p==NULL)
	{
		p=(ptr)malloc(sizeof(node));
		p->data=item;
		p->height=hold+1;
		p->lchild=p->rchild=NULL;
	}
	else if(item<p->data)
	{
		hold++;
		p->lchild=insert(p->lchild,item);
		hold=0;
	}
	else if(item>=p->data)
	{
		hold++;
		p->rchild=insert(p->rchild,item);
		hold=0;
	}
	return p;
}
ptr search(ptr t)
{
	if (t->lchild != NULL)
	search(t->lchild);
	if(t->rchild!=NULL) 
	search(t->rchild);
	if (t->lchild == NULL&&t->rchild==NULL)
	{
		printf("%d %d\n",t->data,t->height);
	}
	return NULL;
}



