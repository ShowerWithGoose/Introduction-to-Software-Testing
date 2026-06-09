#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
struct tree{
	int data;
	struct tree *left;
	struct tree *right;
	int depth;
};
typedef struct tree BTNode;
typedef struct tree *BTNodeptr;
BTNodeptr root=NULL;
int depth=1;
void visit(BTNodeptr t)
{
	printf("%d %d\n",t->data,t->depth);
}
void inorder(BTNodeptr t)
{
	if(t!=NULL)
	{
	    inorder(t->left);
	    if(t->left==NULL&&t->right==NULL)
	    {
	    	visit(t);
		}
		inorder(t->right);
	}
}
BTNodeptr insertBST(BTNodeptr t,int item,int depth)
{
	if(t==NULL)
	{
		t=(BTNodeptr)malloc(sizeof(BTNode));
		t->data=item;
		t->left=t->right=NULL;
		t->depth=depth;
	}
	else if(item<t->data)
	{
		t->left=insertBST(t->left,item,depth+1);
	}
	else 
	{
	    t->right=insertBST(t->right,item,depth+1);
	}
	return t;
}
int main()
{
	int n,m,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		root=insertBST(root,m,1);
	}
	inorder(root);
	return 0;
}

