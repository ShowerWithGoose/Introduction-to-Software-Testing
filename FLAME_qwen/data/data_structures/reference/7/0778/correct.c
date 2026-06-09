#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};
typedef struct tree BTNode,*BTNodeptr;
BTNodeptr root=NULL;

BTNodeptr insertBST(BTNodeptr p,int item);
void preorder(BTNodeptr t,int depth);
int main()
{
	int n;
	int m;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		root=insertBST(root,m);
	}
	preorder(root,1);
	return 0;
}
void preorder(BTNodeptr t,int depth)
{
	if(t!=NULL)
	{
		if(t->left==NULL&&t->right==NULL)
		{
			printf("%d %d\n",t->data,depth);
		 } 
		preorder(t->left,depth+1);
		preorder(t->right,depth+1);
	}
}
BTNodeptr insertBST(BTNodeptr p,int item)
{
	if(p==NULL)
	{
		p=(BTNodeptr)malloc(sizeof(BTNode));
		p->data=item;
		p->left=p->right=NULL;
	}
	else if(item<p->data)
		p->left=insertBST(p->left,item);
	else if(item>=p->data)
		p->right=insertBST(p->right,item);
	return p;
 } 

