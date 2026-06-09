#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int h=1; 
struct node{
	int data,height;
	struct node *left,*right;
};
struct node* initial(struct node *p,int d)
{
	if(p==NULL)
	{
		p=(struct node*)malloc(sizeof(struct node));
		p->data=d;
		p->height=h;
		p->left=p->right=NULL;
	}
	else
	{
		h++;
		if(d<p->data)
		p->left=initial(p->left,d);
		else
		p->right=initial(p->right,d);
	}
	return p;
}
void searchleaf(struct node *p)
{
	if(p!=NULL)
	{
		if(p->left==NULL&&p->right==NULL)
		printf("%d %d\n",p->data,p->height);
		else
		{
			searchleaf(p->left);
			searchleaf(p->right);
		}
	}
}
int main()
{
	struct node *root=NULL;
	int i,j,k,n,d;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&d);
		h=1;
		root=initial(root,d);
	}
	searchleaf(root);
	return 0;
}

