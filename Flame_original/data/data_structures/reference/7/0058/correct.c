#include<stdio.h>
#include<string.h>
struct node{
	int data;
	int depth;
	struct node*left;
	struct node*right;
};
struct node* tmp;
struct node* root;

void append(struct node* root,struct node* tmp)
{
	tmp->depth=root->depth+1;
	if(tmp->data<root->data)
	{
		if(root->left==NULL) root->left=tmp;
		else append(root->left,tmp);
	}
	else
	{
		if(root->right==NULL) root->right=tmp;
		else append(root->right,tmp);		
	}
		
}

void dfs(struct node* root)
{
	if(root->left!=NULL)   
		dfs(root->left);
	if(root->left==NULL&&root->right==NULL)
	{
		printf("%d %d\n",root->data,root->depth);		
	}
	if(root->right!=NULL)
		dfs(root->right);
	
}

int main()
{
	int n,i;
	scanf("%d",&n);
	
	root=malloc(sizeof(struct node));
	root->left=NULL;
	root->right=NULL;
	
	
	scanf("%d",&root->data);
	root->depth=1;
	for(i=0;i<n-1;i++)
	{
		tmp=malloc(sizeof(struct node));
		tmp->left=NULL;
		tmp->right=NULL;
		scanf("%d",&tmp->data);
		append(root,tmp);
	}
	dfs(root);
	
	return 0;
	
}

