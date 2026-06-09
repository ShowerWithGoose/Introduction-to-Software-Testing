#include<stdlib.h>
#include<stdio.h>
typedef struct node
{
	int data,high;
	struct node *left,*right;
} Node;
Node *New(Node *root,int t,int l)
{
	l++;
	if(root==NULL)
	{
		root=(Node *)malloc(sizeof(Node));
		root->data=t;root->high=l;
		root->left=NULL;root->right=NULL;
	}
	else if(t<root->data) root->left=New(root->left,t,l);
	else root->right=New(root->right,t,l);
	return root;
}
void print(Node *root)
{
	if(root)
	{
		if(!(root->left)&&!(root->right))
		{
			printf("%d %d\n",root->data,root->high);
			return ;
		}
		print(root->left);
		print(root->right);
	}
}
int main()
{
	int n,x,h;
	Node *tree=NULL;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		h=0;
		tree=New(tree,x,h);
	}
	print(tree);
}

