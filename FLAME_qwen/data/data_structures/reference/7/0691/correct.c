#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int num;
	struct node *lchild,*rchild;
}node;
node* insert(node* root,int a)
{
	if(root==NULL)
	{
		node *p;
	    p=(node*)malloc(sizeof(node));
	    p->num=a;
	    p->rchild=p->lchild=NULL;
	    return p;
	}	
	else if(a<root->num)
	{
		root->lchild=insert(root->lchild,a);
	}
	else if(a>=root->num)
	{
		root->rchild=insert(root->rchild,a);
	}
	return root;
}
void postorder(node* root,int level)
{
	if(root!=NULL)
	{
		postorder(root->lchild,level+1);
		postorder(root->rchild,level+1);
		if(root->lchild==NULL&&root->rchild==NULL) printf("%d %d\n",root->num,level);
	}
}
int main()
{
	int i,n,a;
	scanf("%d",&n);
	node *root=NULL;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		root=insert(root,a);
	}
    postorder(root,1);

	return 0;
}


