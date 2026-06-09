#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct tree{
	int item;
	int depth;
	struct tree *left;
	struct tree *right;
}*Root=NULL; 
typedef struct tree BST;
typedef struct tree *BP;
void insert(int n)
{
	BP p,q;
	int h=1;
	p=(BP)malloc(sizeof(BST));
	p->item=n;
	p->left=NULL;
	p->right=NULL;
	if(Root==NULL)
	{
		p->depth=h;
		Root=p;
	}
	else
	{
		q=Root;
		while(1)
		{
			if(n<q->item)
			{
				if(q->left==NULL)
				{
					h++;
					p->depth=h;
					q->left=p;
					break;
				}
				else
				{
					q=q->left;
					h++;
				}
			}
			else
			{
				if(q->right==NULL)
				{
					h++;
					p->depth=h;
					q->right=p;
					break;
				}
				else
				{
					q=q->right;
					h++;
				}
			}
		}
	}
}
void inorder(BP t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		if(t->left==NULL&&t->right==NULL)printf("%d %d\n",t->item,t->depth);
		inorder(t->right);
	}
}
int main()
{
	int a,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&a);
		insert(a);
	}
	inorder(Root);
    return 0;
}


