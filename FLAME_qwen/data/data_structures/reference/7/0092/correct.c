#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node{
	int data, depth;
	struct node *lchild,*rchild;
}tree,*treep;
treep root=NULL;
void visit(treep *t)
{
	if(*t!=NULL)
	{
		visit(&((*t)->lchild));
		if(((*t)->lchild)==NULL&&(*t)->rchild==NULL)
		printf("%d %d\n",(*t)->data,(*t)->depth);
		visit(&((*t)->rchild));
	}
}
void insert(treep *t,int depth,int data)
{
	if(*t==NULL)
	{
		*t=(treep)malloc(sizeof(tree));
		(*t)->lchild=(*t)->rchild=NULL;
		(*t)->data=data;
		(*t)->depth=depth;
	}
	else if(data<(*t)->data)
	{
		insert(&((*t)->lchild),depth+1,data);
	}
	else if(data>=(*t)->data)
	{
		insert(&((*t)->rchild),depth+1,data);
	}	
}
int main()
{
	int i,n,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		insert(&root,1,x);
	}
	visit(&root);
	return 0;
}

