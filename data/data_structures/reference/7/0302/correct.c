#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	int depth;
	struct node *left;
	struct node *right;
}tree,*treep;
int depth=1;
treep root=NULL;
treep insertbst(treep t,int data,int depth)
{
	if(t==NULL)
	{
		t=(treep)malloc(sizeof(tree));
		t->data=data;
		t->depth=depth;
		t->left=NULL;
		t->right=NULL;
	}
	else
	{
		if(data<t->data)
			t->left=insertbst(t->left,data,depth+1);
		else
			t->right=insertbst(t->right,data,depth+1);
	}
	return t;
}
void put(treep t)
{
	if(t!=NULL)
	{
		put(t->left);
		if(t->left==NULL&&t->right==NULL)
			printf("%d %d\n",t->data,t->depth);
		put(t->right);
	}
}
int main()
{
	int i,n,data[114];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
		root=insertbst(root,data[i],depth);
	}
	put(root);
}
/*13
50 38 30 64 58 40 10 73 70 50 60 100 35*/



