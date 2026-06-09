#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define maxsize 1000
typedef struct btNode{
    int data;
    struct btNode *lchild;
    struct btNode *rchild;
    int depth;
}BTNode,*PBTNode;
int m,i,n;
int depth=1;
PBTNode root=NULL;
void visit(PBTNode t);// 访问结点 

void inorder(PBTNode t)
{
    if(t!=NULL){
        inorder(t->lchild);
        if(t->lchild==NULL && t->rchild==NULL)	
		visit(t);      // 访问t指的叶子结点 
        inorder(t->rchild);
    }
}
void InsertBST(PBTNode *t,int item,int depth);
int main()
{	
	int j=0;
	scanf("%d",&n);
	for(j=0;j<n;j++);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		InsertBST(&root,m,1);
	}
	inorder(root);
	return 0;
}

void InsertBST(PBTNode *t,int item,int depth) //构造BST 
{
	if(*t==NULL)
	{
		*t=(PBTNode)malloc(sizeof(PBTNode));
		(*t)->lchild=(*t)->rchild=NULL;
		(*t)->data=item;
		(*t)->depth=depth;
	}
	else if(item<(*t)->data)
	{
		InsertBST(&((*t)->lchild),item,depth+1);
	} 
	else
	{
		InsertBST(&((*t)->rchild),item,depth+1);
	} 
}
void visit(PBTNode t)// 访问结点 
{
	printf("%d %d\n",t->data,t->depth);
}



