#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int value;
	int height;
	struct tree *right;
	struct tree *left;
};
void buildtree(int);
struct tree *root=NULL;
int main()
{
	int n=0,num=0,top=-1;
	struct tree *p[100],*q=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num);
		buildtree(num);
	}
	q=root;
	do{
		if(q!=NULL)
		{
			p[++top]=q;
			q=q->left;
		}
		else
		{
			q=p[top--];
			if(q->left==NULL&&q->right==NULL)
				printf("%d %d\n",q->value,q->height);
			q=q->right;
		}
	}while(top!=-1||q!=NULL);
	return 0;
}
void buildtree(int x)
{
	int judge=-1;
	struct tree *q=NULL,*temp=NULL,*p=NULL;
	q=(struct tree *)malloc(sizeof(struct tree));
	q->value=x;
	q->height=1;
	q->left=q->right=NULL;
	if(root==NULL)
		root=q; 
	else
	{
		temp=root;
		while(temp!=NULL)
		{
			p=temp;
			if(q->value<temp->value)
			{
				temp=temp->left;
				judge=0;
			}
			else
			{
				temp=temp->right;
				judge=1;
			}
			q->height++;
		}
		if(judge==0)
			p->left=q;
		else
			p->right=q;
	}
	return;	
} 

