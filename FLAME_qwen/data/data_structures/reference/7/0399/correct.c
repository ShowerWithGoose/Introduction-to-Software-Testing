#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *left,*right;
	int depth;
};
typedef struct node BTNode,*BTNodeptr;
BTNodeptr insertBST(BTNodeptr p,int item,int depth)
{
	if(p==NULL)//结点为空 
	{
		p=(BTNodeptr)malloc(sizeof(BTNode));
		p->data=item;
		p->left=p->right=NULL;
		p->depth=depth;
	}
	else if(item<p->data)//小于结点 
	{
		p->left = insertBST(p->left,item,depth+1);
	}
	else if(item>=p->data)//大于等于节点 
	{
		p->right = insertBST(p->right,item,depth+1);
	}
	return p;
}

void inorder(BTNodeptr p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		if(p->left==NULL && p->right==NULL)
		printf("%d %d\n",p->data,p->depth);
		inorder(p->right);
	}
}

int main()
{
	int i,item,m;
	BTNodeptr root=NULL;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&item);
		root = insertBST(root,item,1);
	}
	if(root == NULL){
		printf("ERROR!");
	}
	else{
		inorder(root);
	}
	return 0;
}

