#include<stdio.h>
#include<stdlib.h>
struct BT{
	int data;
	struct BT *lchild, *rchild;
	int h;
}*queue[200];
struct BT* insert(struct BT *, int);
void LayerBianli(struct BT *);
void Bianli(struct BT *); 
int main()
{
	int tmp, n, i;
	scanf("%d", &n);
	//逐点插入构造二叉树
	struct BT *root=NULL; 
	for(i=0; i<n; i++)
	{
		scanf("%d",&tmp);
		root=insert(root, tmp); 
	}
	//层次遍历
	LayerBianli(root);
	//遍历
	Bianli(root);
	return 0;
}

struct BT* insert(struct BT *p, int d)
{
	if(p==NULL)
	{
		p=(struct BT *)malloc(sizeof(struct BT));
		p->data=d;
		p->lchild=p->rchild=NULL;
		p->h=0;
	}
	else if(d<p->data) p->lchild=insert(p->lchild, d);
	else if(d>=p->data) p->rchild=insert(p->rchild, d);
	return p;
}

void LayerBianli(struct BT *t)
{
	struct BT *p;
	int front, rear;
	if(t!=NULL)
	{
		queue[0]=t;
		front=0;
		rear=1;
		while(front<rear)
		{
			p=queue[front++]; //以p作为根节点 
			if(p->h==0) p->h=1;
			if(p->lchild!=NULL)
			{
				queue[rear]=p->lchild;
				queue[rear]->h=(p->h)+1;
				rear++;
			}
			if(p->rchild!=NULL)
			{
				queue[rear]=p->rchild;
				queue[rear]->h=(p->h)+1;
				rear++;
			}
		}
	}
}

void Bianli(struct BT *p)
{
	if(p!=NULL)
	{
		Bianli(p->lchild);
		if(p->lchild==NULL && p->rchild==NULL)
		{
			printf("%d %d\n", p->data, p->h);
		}
		Bianli(p->rchild);
	}
}

