#include<stdio.h>
#include<stdlib.h>
struct shujv
{
	int data;
	int depth;
	struct shujv *left,*right;
};
struct shujv* root;
void shu(struct shujv *root,struct shujv *new)
{
	new->depth++;
	if(root->data>new->data)
	{
		if(root->left==NULL)
		{
			root->left=new;
			return ;
		}
		else shu(root->left,new);
	}
	else
	{
		if(root->right==NULL)
		{
			root->right=new;
			return ;
		}
		else shu(root->right,new);
	}
}
void digui(struct shujv *root)
{
	// 1. DFS on root->left
	if(root->left!=NULL) digui(root->left);
	// 2. Check if root is leaf
	if(root->left==NULL && root->right==NULL){
		printf("%d %d\n",root->data, root->depth);
	}
	// 3. DFS on root->right
	if(root->right!=NULL) digui(root->right);
}
int main()
{
	int n,depth,nm;
	scanf("%d",&n);
	int i=0;
	root=(struct shujv*)malloc(sizeof(struct shujv));
	root->left=NULL;
	root->right=NULL;
	scanf("%d",&root->data);
	root->depth=1;
	for(i=1;i<n;i++)
	{
		struct shujv *nm;
		nm=(struct shujv*)malloc(sizeof(struct shujv));
		nm->left=NULL;
		nm->right=NULL;
		scanf("%d",&nm->data);
		nm->depth=1;
		shu(root,nm);
	}
	digui(root);
	return 0;
}


