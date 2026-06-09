#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct BinTree
{
	int data;
	struct BinTree* Lchild;
	struct BinTree* Rchild;
};
struct BinTree* CreateBinTree(struct BinTree *p,int num)
{
	if(p==NULL)
	{
		p=(struct BinTree*)malloc(sizeof(struct BinTree));
		p->data=num;
		p->Lchild=NULL;
		p->Rchild=NULL;
	}
	else
	{
		if(num<p->data)
		{
			p->Lchild=CreateBinTree(p->Lchild,num);
		}
		else
		{
			p->Rchild=CreateBinTree(p->Rchild,num);
		}
	}
	return p;
};
void pre_order(struct BinTree* p,int ans)
{
	if(p!=NULL)
	{
		if(p->Lchild==NULL&&p->Rchild==NULL)
		{
			printf("%d %d\n",p->data,ans);
		}
		pre_order(p->Lchild,ans+1);
		pre_order(p->Rchild,ans+1);
	}
};
int main()
{
	struct BinTree *Tree;
	int n,i,num;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i==1)
		{
			scanf("%d",&num);
			Tree=(struct BinTree*)malloc(sizeof(struct BinTree));
			Tree->data=num;
			Tree->Lchild=NULL;
			Tree->Rchild=NULL;
		}
		else
		{
			scanf(" %d",&num);
			CreateBinTree(Tree,num);
		}
	}
	pre_order(Tree,1);
	return 0;
}

