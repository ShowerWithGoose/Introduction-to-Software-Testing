#include<stdio.h>
#include<malloc.h>
typedef int DataType;
typedef struct t{
	DataType data;
	struct t *lchild, *rchild;
}BTnode, *BTree;
int  dgr=0, dgrl=0, dgrr=0;
BTree Insert(DataType x,BTree tree);
void PreOrder(BTree tree, int h);
int main()
{
	BTree tree=NULL;
	int n, m;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		tree=Insert(m,tree);
	}
	PreOrder(tree,0);
	return 0;
}
//插入节点创建二叉树
BTree Insert(DataType x,BTree tree)
{
	if(!tree)
	{
		//树为空，生成并返回一个节点的二叉树
		tree=(BTree)malloc(sizeof(BTnode));
		tree->data=x;
		tree->lchild=tree->rchild=NULL; 
	}
	else
	{
		if(x<tree->data)
			tree->lchild=Insert(x,tree->lchild);
		else if(x>=tree->data)
			tree->rchild=Insert(x,tree->rchild);
	}
	return tree;
}
void PreOrder(BTree tree, int h)	//前序遍历(深度优先)
{
	if(tree!=NULL)
	{
		if(tree->lchild==NULL&&tree->rchild==NULL)
			printf("%d %d\n",tree->data, h+1);	
		else
		{
			PreOrder(tree->lchild, h+1);
			PreOrder(tree->rchild, h+1);
		}
	}
}

