#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* lchild;
	struct node* rchild;
	int high;
};
typedef struct node tree;
tree* insertT(tree* p,int y,int x);//插入结点 
void preorder(tree* p);//遍历输出
void visit(tree* p);//访问p 

int main(){
	tree *root;
	int n,i,item;
	
	root=(tree*)malloc(sizeof(tree));
	root->lchild =root->rchild =NULL;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			scanf("%d",&root->data  );
			root->high =1;
		}
		else
		{
			scanf("%d",&item);
			root=insertT(root,item,1);
		}
	}
	
	preorder(root);
	
	return 0;
}
tree* insertT(tree* p,int y,int x)
{
	if(p==NULL)
	{
		p=(tree*)malloc(sizeof(tree));
		p->data =y;
		p->high =x;
		p->lchild =NULL;
		p->rchild =NULL;
		
	}
	else if(p->data >y)
	{
		p->lchild =insertT(p->lchild ,y,x+1);
	}
	else
	{
		p->rchild =insertT(p->rchild ,y,x+1);
	}
	return p;
}

void preorder(tree* p)
{
	if(p!=NULL)
	{
		preorder(p->lchild );
		visit(p);
		preorder(p->rchild );
	}
}

void visit(tree* p)
{
	if(p->lchild ==NULL&&p->rchild ==NULL)
		{
			printf("%d %d\n",p->data,p->high );
		}
}


