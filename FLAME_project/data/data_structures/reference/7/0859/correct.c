#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Tree{
	 int num;
	 int high;
	 struct Tree *llink;
	 struct Tree *rlink;
}Tree;
Tree *p,*q,*head=NULL;
void read(Tree *root);
int a[500];
int main()
{
	int n;
	scanf("%d",&n);
	int i=0,height=1;
	int op,max;
	int len=0;
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		op=a[i];
		height=1;
		p=(Tree *)malloc(sizeof(Tree));
		p->llink=NULL;
		p->rlink=NULL;
		p->num=op;
		if(head==NULL)
		{
			p->num=op;
			p->high=height;
			q=head=p;
		}
		else
		{
			q=head;
			while(1)
			{
				if(op>=q->num)
				{
					if(q->rlink==NULL)
					break;
					q=q->rlink;
				}
				else if(op<q->num)
				{
					if(q->llink==NULL)
					break;
					q=q->llink;
				}
				height++;
			}
			p->high=height+1;
			if(q->llink==NULL&&op<q->num)
			q->llink=p;
			else if(q->rlink==NULL&&op>q->num)
			q->rlink=p;
		}
	}
	read(head);
	return 0;
}
void read(Tree *root)
{
	if(root!=NULL)
	{ 
	if(root->llink==NULL&&root->rlink==NULL)
	printf("%d %d\n",root->num,root->high);
	else
	{
		read(root->llink);
		read(root->rlink);
	}
	}
}

