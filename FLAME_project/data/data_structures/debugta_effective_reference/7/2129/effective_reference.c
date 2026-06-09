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

BTNodeptr insertBST(BTNodeptr p,int m);
void preorder(BTNodeptr node,int depth);
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
void preorder(BTNodeptr node,int depth)
{
	if(node!=NULL)
	{
		if(node->left==NULL&&node->right==NULL)
		{
			printf("%d %d\n",node->data,depth);
		 } 
		preorder(node->left,depth+1);
		preorder(node->right,depth+1);
	}
}
BTNodeptr insertBST(BTNodeptr p,int m)
{
	if(p==NULL)
	{
		p=(BTNodeptr)malloc(sizeof(BTNode));
		p->data=m;
		p->left=p->right=NULL;
	}
	else if(m<p->data)
		p->left=insertBST(p->left,m);
	else if(m>=p->data)
		p->right=insertBST(p->right,m);
	return p;
 } 

