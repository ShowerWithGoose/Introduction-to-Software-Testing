#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
	int data;
	int high;
	struct tree *lchild;
	struct tree *rchild;
}bst,*higtree;
higtree insert(higtree p,int item,int i)
{
	if(p==NULL)
	{
		p=(higtree)malloc(sizeof(bst));
		p->data=item;
		p->high=i+1;
		p->lchild=p->rchild=NULL;
	}
	else if(item<p->data)
		p->lchild=insert(p->lchild,item,p->high);
	else
		p->rchild=insert(p->rchild,item,p->high);
	return p;
}
void put(higtree t)
{
	if(t!=NULL)
	{
		put(t->lchild);
		if(t->lchild==NULL&&t->rchild==NULL)
		printf("%d %d\n",t->data,t->high);
		put(t->rchild);
	}
}
int main()
{
	int n,item;
	int i;
	higtree root=NULL;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&item);
		root=insert(root,item,0);
	}
	put(root);
	return 0;
}

