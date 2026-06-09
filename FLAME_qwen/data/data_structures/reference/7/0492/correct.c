#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node
{
	int data;
	int h;
	struct node *l,*r;
}Tree;
Tree *first;
Tree *New(Tree *root,int temp,int len);
void print(Tree *root);
int main()
{
	Tree *root=NULL;
	int n,temp,i=0,len;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		root=New(root,temp,len);
	}
	print(root);
	return 0;
}
Tree *New(Tree *root,int temp,int len)
{
	len++;
	if(root==NULL)
	{
		root=(Tree*)malloc(sizeof(Tree));
		root->data=temp;
		root->l=root->r=NULL;
		first=root;
		root->h=len;
	}
	else if(temp<root->data)
	    root->l=New(root->l,temp,len);
	else if(temp>=root->data)
	    root->r=New(root->r,temp,len);
	return root;
}
void print(Tree *root)
{
	if(root)
	{
		if(!(root->l)&&!(root->r))
		{
			printf("%d %d\n",root->data,root->h);
		}
		print(root->l);
	    print(root->r);
	}
}


