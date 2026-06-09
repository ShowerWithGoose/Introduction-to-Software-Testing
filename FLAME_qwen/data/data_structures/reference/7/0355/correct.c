#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct node
{
	int date;
	struct node *left,*right,*parent;
};
struct node *root=NULL;
void insertbst(int item)
{
	struct node *p,*q;
	p=(struct node *)malloc(sizeof(struct node));
	p->date=item;
	p->left=p->right=p->parent=NULL;
	if(root==NULL)
		root=p;
	else
	{
		q=root;
		while(1)
		{
			if(item<q->date)
			{
				if(q->left==NULL)
				{
					q->left=p;
					p->parent=q;
					break;
				}
				else
					q=q->left;
			}
			else
			{
				if(q->right==NULL)
				{
					q->right=p;
					p->parent=q;
					break;
				}
				else
					q=q->right;
			}
		}
	}
}
void inorder(struct node *t)
{
	struct node *p;
	if(t!=NULL)
	{
		inorder(t->left);
		if(t->left==NULL&&t->right==NULL)
		{
			int h=1;
			for(p=t;p->parent!=NULL;p=p->parent)
				h++;
			printf("%d %d\n",t->date,h);
		}
		inorder(t->right);
	}
}
int main()
{
	int m,i,item;
	scanf("%d",&m);
	for(i=0; i<m; i++)
	{
		scanf("%d",&item);
		insertbst(item);
	}
	inorder(root);
	return 0;
}


