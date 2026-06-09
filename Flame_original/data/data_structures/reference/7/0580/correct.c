#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
struct node
{
	int data;
	int decker;
	struct node* right;
	struct node* left;
};
void insert(struct node **tree,int gain,int num)
{
	struct node* t=NULL;
	if(!(*tree))
	{
		t=(struct node*)malloc(sizeof(struct node));
		t->right=NULL;
		t->left=NULL;
		t->data=gain;
		t->decker=num;
		*tree=t;
		return; 
	}
	if(gain<(*tree)->data)
	{
		insert(&(*tree)->left,gain,num+1);
	}
	else
	{
		insert(&(*tree)->right,gain,num+1);
	}
}
void deletree(struct node* tree)
{
	if(tree)
	{
		deletree(tree->left);
		deletree(tree->right);
		free(tree);
	}
}
void print(struct node* tree)
{
	if(tree->left==NULL && tree->right==NULL)
	{
		printf("%d %d\n",tree->data,tree->decker);
	}
	else
	{
		if(tree->left!=NULL)
		{
			print(tree->left);
		}
		if(tree->right!=NULL)
		{
			print(tree->right);
		}
	}
}
int main()
{
	int n,a,i;
	struct node* root;
	root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		insert(&root,a,1);
	}
	print(root);
	return 0;
}

