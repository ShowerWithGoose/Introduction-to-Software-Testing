#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	int height;
	struct node *lchild,*rchild;
};
struct node *add(struct node *root,int num,int h)
{
	    h++; 
		if(root==NULL)
		{
			root=(struct node*)malloc(sizeof(struct node));
		    root->data=num;
		    root->height=h;
		    root->lchild=NULL;
		    root->rchild=NULL;
		}
		else if(num<root->data)
		{
			root->lchild=add(root->lchild,num,h);
		}
		else if(num>=root->data)
		{
			root->rchild=add(root->rchild,num,h);
		}
		return root;
}
void print(struct node *root)
{
	if(root!=NULL)
	{
		if(root->lchild==NULL&&root->rchild==NULL)
		{
			printf("%d %d\n",root->data,root->height);
		}
		print(root->lchild);
		print(root->rchild);
	}
}
int main()
{
	struct node *root=NULL; 
	int n,num,i,h;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		h=0;
		root=add(root,num,h);
	}
	print(root);
	return 0;
}

