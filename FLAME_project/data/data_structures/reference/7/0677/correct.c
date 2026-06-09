#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
13
50 38 30 64 58 40 10 73 70 50 60 100 35
*/
struct node{	//定义结点 
	int data;
	int high;
	struct node *lchild,*rchild;
};
typedef struct node BTnode;
typedef struct node* BTnodeptr;
BTnodeptr insert(BTnodeptr p,int item)		//构造bts 
{
	if(p==NULL)
	{
		p=(BTnodeptr)malloc(sizeof(BTnode));
		p->data=item;
		p->lchild=p->rchild=NULL;
	}else if(item < p->data){
		p->lchild=insert(p->lchild,item);
	}else if(item >= p->data){
		p->rchild=insert(p->rchild,item);
	}
	return p;
}
void inorder(BTnodeptr t,int high)	//中序遍历 
{
	if(t!=NULL)
	{
		inorder(t->lchild,high+1);
		printf("%d %d\n",t->data,high);
		inorder(t->rchild,high+1);
	}
}
void postorder(BTnodeptr t,int high)	//后序遍历
{
	if(t->lchild!=NULL)
		postorder(t->lchild,high+1);
	if(t->rchild!=NULL)
		postorder(t->rchild,high+1);
	if(t->lchild==NULL&&t->rchild==NULL)
		printf("%d %d\n",t->data,high);
}
int main()
{
	BTnodeptr root;
	root=NULL;
	int n,item;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++)
	{
		scanf("%d",&item);
		root=insert(root,item);
	}
//	inorder(root,1);
	postorder(root,1);
	
	
}



