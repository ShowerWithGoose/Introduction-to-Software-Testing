#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct L{
	struct L *lchild;
	int data;
	struct L *rchild;
};
typedef struct L node;
typedef struct L *nodeptr;
nodeptr insert(nodeptr p, int x)
{
	if(p==NULL)
	{
		p=(nodeptr)malloc(sizeof(nodeptr));
		p->data=x;
		p->lchild=NULL;
		p->rchild=NULL;
//		printf("插入结点data=%d\n",x);
	}
	else if(x<p->data)
	{
		p->lchild=insert(p->lchild,x);
	}
	else
	{
		p->rchild=insert(p->rchild,x);
	}
	return p;
}
void pu(nodeptr p,int d)
{
	if(p->lchild == NULL && p->rchild == NULL)
	{
		printf("%d %d\n",p->data,d);
	}
	return ;
}
void preorder(nodeptr p, int d)
{
	if(p!=NULL)
	{
//		printf("访问结点值为%d\n",p->data);
		pu(p,d);
		preorder(p->lchild,d+1);
		preorder(p->rchild,d+1);
	}
	return ;
}
int main() {
	int n,i,x;
	scanf("%d",&n);
	nodeptr root=NULL;
	
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		root=insert(root,x);
	}
	
	preorder(root,1);
	
	
	
	return 0;
}

