#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild,*rchild;
}BiNode,*BiTree;
typedef struct Tree
{
    BiTree root;
}Tree,*Root;
BiTree p0=NULL;
void insert(Root tree,int val)
{ 
    if(tree==NULL)  return ;
    BiTree node=(BiTree)malloc(sizeof(BiNode));
    node->data=val;      
    node->lchild=NULL;
    node->rchild=NULL;
    if(tree->root==NULL)
	{       
        tree->root=node;
    }
	else
	{                      //不是空树
        BiTree temp=tree->root; //temp用于遍历树的变量
        while(temp)//等价于temp!=NULL
		{   
            if(temp->data<=val)//val大，往右走
			{ 
                if(temp->rchild==NULL)//右孩子为空，直接插入
				{ 
                    temp->rchild=node;
                    return;            //退出
                }
				else
				{
                    temp=temp->rchild; //否则继续往右子树比
                }
            }
            else
			{
                if(temp->lchild==NULL)//左孩子为空，直接插入
				{ 
                    temp->lchild=node;
                    return ;
                }
				else//否则继续往左子树比
				{
                    temp=temp->lchild; 
                }
            }
        }
    }
}
int getn(BiTree p0,BiTree p)
{
	int d1,d2;
	if(p0==NULL) return 0;
	if(p0==p) return 1;
	d1=getn(p0->lchild,p);
	d2=getn(p0->rchild,p);
	if(d1 || d2) return 1+(d1>d2?d1:d2);
	return 0;
}
void midVisit(BiTree node)
{
    if(node==NULL)
	{
        return ;
    }
    else
	{

        midVisit(node->lchild);
        if(node->lchild==NULL && node->rchild==NULL)
        printf("%d %d\n",node->data,getn(p0,node));
        midVisit(node->rchild);
    }
}
void tree_Free(BiTree  T)//后序删除 
{
	if(T == NULL)
	  	return;
	if(T->lchild != NULL)
	{
	  	tree_Free(T->lchild);//先向下free 
	  	T->lchild = NULL;//再将其本身free 
	}
	if(T->rchild != NULL)
	{
	  	tree_Free(T->rchild);
	  	T->rchild = NULL;
	}
	if(T != NULL)//最后删除根节点 
	{
	  	free(T);
	  	T = NULL;
	}
}
int main()
{
    int val;
    Root tree=(Root)malloc(sizeof(Tree));
    tree->root=NULL;
    int n=0;
    scanf("%d",&n);
    while(n--)
	{
		scanf("%d",&val);
        insert(tree,val);
    }
    p0=tree->root;
    midVisit(tree->root);
    tree_Free(tree->root);
    return 0;
}

