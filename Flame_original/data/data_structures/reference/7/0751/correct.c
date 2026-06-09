#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct node 
{
    int data;
	int depth;
    struct node *left;
    struct node *right;
}tree;
int m,i,n,depth=1;
tree *root=NULL;
void VISIT(tree* t) 
{
    if (t)
    {
        if (!(t->left) && !(t->right))
          printf("%d %d\n", t->data, t->depth);
        VISIT(t->left);
        VISIT(t->right);
    }
}

void *BST(tree *t,int value,int depth) 
{
	if(t==NULL)
	{
		t=(tree *)malloc(sizeof(tree));
		t->left=t->right=NULL;
		t->data=value;
		t->depth=depth;
	}
	else if(value<(t->data))
		t->left=BST(t->left,value,depth+1);
	else
		t->right=BST(t->right,value,depth+1);
    return t;
}
int main()
{	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		root=BST(root,m,1);
	}
	VISIT(root);
	return 0;
}

