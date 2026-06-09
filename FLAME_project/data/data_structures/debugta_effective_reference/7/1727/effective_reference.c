#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct bst{
	int num,high;
	struct bst *left,*right;
};
void intree(struct bst *bst,struct bst *q);
void outtree(struct bst *bst);
void destroytree(struct bst *bst);
int main()
{
	struct bst *bst=NULL,*q=NULL;
	int n=0,i=1,num=0;
	scanf("%d",&n);
	scanf("%d",&num);
	bst=malloc(sizeof(struct bst));
	bst->num =num;
	bst->high =1;
	bst->left =NULL;
	bst->right =NULL;
	for(i=1;i<n;i++)
	{
		scanf("%d",&num);
		q=malloc(sizeof(struct bst));
		q->num =num;
		q->high =0;
		q->left =NULL;
		q->right =NULL;
		intree(bst,q);
	}
	outtree(bst);
	destroytree(bst);
	return 0;
}
void intree(struct bst *bst,struct bst *q)
{
	struct bst *p=bst;
	int h=1;
	while(1)
	{
		h++;
		if(q->num >=p->num )
		{
			if(p->right !=NULL)
			{
				p=p->right ;
			}
			else
			{
				q->high =h;
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
				q->high =h;
				p->left =q;
				break;
			}
		}
	}	
}
void outtree(struct bst *bst)
{
	if(bst!=NULL)
	{
		if(bst->left ==NULL&&bst->right ==NULL)
		{
			printf("%d %d\n",bst->num ,bst->high );
		}
		else
		{
			outtree(bst->left );
			outtree(bst->right );
		}
	}
	
}
void destroytree(struct bst *bst)
{
	if(bst!=NULL)
	{
		destroytree(bst->left );
		destroytree(bst->right );
		free(bst);
	}
}

