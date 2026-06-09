#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct bst{
	int num,high;
	struct bst *left,*right;
};
void intree(struct bst *tree,struct bst *q);
void outtree(struct bst *tree);
void destroytree(struct bst *tree);
int main()
{
	struct bst *tree=NULL,*q=NULL;
	int n=0,i=1,temp=0;
	scanf("%d",&n);
	scanf("%d",&temp);
	tree=malloc(sizeof(struct bst));
	tree->num =temp;
	tree->high =1;
	tree->left =NULL;
	tree->right =NULL;
	for(i=1;i<n;i++)
	{
		scanf("%d",&temp);
		q=malloc(sizeof(struct bst));
		q->num =temp;
		q->high =0;
		q->left =NULL;
		q->right =NULL;
		intree(tree,q);
	}
	outtree(tree);
	destroytree(tree);
	return 0;
}
void intree(struct bst *tree,struct bst *q)
{
	struct bst *p=tree;
	int j=1;
	while(1)
	{
		j++;
		if(q->num >=p->num )
		{
			if(p->right !=NULL)
			{
				p=p->right ;
			}
			else
			{
				q->high =j;
				p->right =q;
				break;
			}
		}
		else if(q->num <p->num )
		{
			if(p->left !=NULL)
			{
				p=p->left ;
			}
			else
			{
				q->high =j;
				p->left =q;
				break;
			}
		}
	}	
}
void outtree(struct bst *tree)
{
	if(tree!=NULL)
	{
		if(tree->left ==NULL&&tree->right ==NULL)
		{
			printf("%d %d\n",tree->num ,tree->high );
		}
		else
		{
			outtree(tree->left );
			outtree(tree->right );
		}
	}
	
}
void destroytree(struct bst *tree)
{
	if(tree!=NULL)
	{
		destroytree(tree->left );
		destroytree(tree->right );
		free(tree);
	}
}

