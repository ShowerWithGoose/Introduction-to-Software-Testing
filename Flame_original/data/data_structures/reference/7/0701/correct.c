#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *left,*right;
};
struct node* insert(struct node*root,int data)
{
	struct node *p;
	if(root==NULL)
	{
        p=(struct node*)malloc(sizeof(struct node)); 
        p->data=data; 
        p->left=p->right=NULL; 
        return p; 
    }
    else if (data<root->data) 
        root->left=insert(root->left, data); 
    else 
        root->right=insert(root->right, data);
    return root;
}
void print(struct node *root,int height)
{
	if(root->left!=NULL)
	{
		print(root->left,height+1);
	}
	if(root->right!=NULL)
	{
		print(root->right,height+1);
	}
	if(root->left==NULL&&root->right==NULL)
	{
		printf("%d %d\n",root->data,height);
	}
}
int main()
{
	struct node *p,*q,*root;
	root=NULL;
	int n,i,j,k,num;
	scanf("%d",&n);
	root=(struct node*)malloc(sizeof(struct node));
	root=NULL;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num);
		root=insert(root,num);
	}
	print(root,1);
	return 0;
}

