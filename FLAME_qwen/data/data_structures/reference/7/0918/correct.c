#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
typedef struct tree
{
	int value;
	struct tree *left;
	struct tree *right;
	int depth;
}Tree,*Treep;
Treep root=NULL;
int depth=1;
void order(Treep t)
{
	if(t!=NULL)
	{
		order(t->left);
		if(t->left==NULL&&t->right==NULL)
		{
			printf("%d %d\n",t->value,t->depth);
		}
		order(t->right);
	}
}
void bst(Treep *t,int value,int depth)
{
	if(*t==NULL)
	{
		*t=(Treep)malloc(sizeof(Treep));
		(*t)->left=(*t)->right=NULL;
		(*t)->value=value;
		(*t)->depth=depth;
	}
	else if(value<((*t)->value))
	{
		bst(&((*t)->left),value,depth+1);
	}
	else{
		bst(&((*t)->right),value,depth+1);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int m;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		bst(&root,m,depth);
	}
	order(root);
	return 0;
	
}

