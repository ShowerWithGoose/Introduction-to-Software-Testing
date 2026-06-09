#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h> 
//printf("!\n");

struct TNode
{
	struct TNode *lchild;
	int data;
	int height;
	struct TNode *rchild;
};
typedef struct TNode *PNode;

void preorder(PNode str)
{
	if(str->lchild!=NULL||str->rchild!=NULL)
	{
		if(str->lchild!=NULL)
		{
			preorder(str->lchild);
		}
		if(str->rchild!=NULL)
		{
			preorder(str->rchild);
		}
	}
	else
	{
		printf("%d %d\n",str->data,str->height);
	}
}
int a[500];
int main()
{
	int n;
	int flag;
	int i,j;
	PNode root=(PNode)malloc(sizeof(struct TNode));
	PNode p=root;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	root->height=1;
	root->data=a[0];
	root->lchild=NULL;
	root->rchild=NULL;
	for(j=1;j<i;j++)
	{
//		printf("? ");
		flag=2;
		p=root;
		for(;(p->data>a[j]&&p->lchild!=NULL)||(p->data<=a[j]&&p->rchild!=NULL);flag++)
		{
			if(p->data>a[j]) p=p->lchild;
			else p=p->rchild; 
//			printf("flag=%d ",flag);
		}
		PNode q=(PNode)malloc(sizeof(struct TNode));
		q->data=a[j];
		q->height=flag;
//		printf("q->data=%d ",q->data);
//		printf("q->height=%d\n",q->height);
		if(p->data>a[j])
		{
			p->lchild=q;
			p=q;
			p->lchild=NULL;
			p->rchild=NULL;
		}
		else
		{
			p->rchild=q;
			p=q;
			p->lchild=NULL;
			p->rchild=NULL;
		}
//		printf("p->data=%d,p->height=%d\n",p->data,p->height); 
	}
	preorder(root);
	return 0;
}

