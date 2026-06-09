#include<stdio.h>
#include<stdlib.h>

typedef struct TREE
{
	int data;
	int depth;
	struct TREE *lchild,*rchild;
}*BTptr,BT;

int n;
BTptr root;

void BST_Insert(int data);
void Knot_Depth(BTptr Root,int num);
void DLRorder(BTptr Root);

int main()
{
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		BST_Insert(a[i]);
	}
	Knot_Depth(root,0);
	DLRorder(root);
	return 0;
}

void DLRorder(BTptr Root)
{
	BTptr stack[n],p=Root;
	int top=-1;
	do
	{
		if(p!=NULL)
		{
			if(p->rchild==NULL && p->lchild==NULL) printf("%d %d\n",p->data,p->depth);
			stack[++top]=p;
			p=p->lchild;
		}
		else
		{
			p=stack[top--];
			p=p->rchild;
		}
	}while(p!=NULL || top!=-1);
}

void Knot_Depth(BTptr Root,int num)
{
	if(Root!=NULL)
	{
		Root->depth=++num;
		Knot_Depth(Root->lchild,num);
		Knot_Depth(Root->rchild,num);
	}
}

void BST_Insert(int data)
{
	BTptr p,q;
	p=(BTptr)malloc(sizeof(BT));
	p->data=data; p->lchild=NULL; p->rchild=NULL;
	if(root==NULL)
	{
		root=p;
		return ;
	}
	q=root;
	while(1)
	{
		if(q->data>data)
		{
			if(q->lchild==NULL)
			{
				q->lchild=p;
				break;
			}
			else q=q->lchild;
		}
		else
		{
			if(q->rchild==NULL)
			{
				q->rchild=p;
				break;
			}
			else q=q->rchild;
		}
	}
}
