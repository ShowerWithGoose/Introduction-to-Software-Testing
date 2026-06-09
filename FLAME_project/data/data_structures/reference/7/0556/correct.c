#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>


typedef struct Node{
	int data;
	struct Node *left,*right; 
}BTNODE,*PBTNODE;
PBTNODE	insertBST(PBTNODE p,int item);//二叉查找树的建立
void PreLeaves(PBTNODE t,int );//先序遍历叶节点 
int Max(int x,int y);
int heightTree(PBTNODE p);


int main()
{
	int n,item;
	PBTNODE root=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&item);
		root=insertBST(root,item);
	}
	PreLeaves(root,0);
	
	return 0;
}
PBTNODE	insertBST(PBTNODE p,int item)
{
	if(p==NULL)//根节点 
	{
		p=(PBTNODE)malloc(sizeof(BTNODE));
		p->data=item;
		p->left=p->right=NULL;
	}
	else if(item<p->data)
	{
		p->left=insertBST(p->left,item);
		
	}
	else if(item>=p->data)
	{
		p->right=insertBST(p->right,item);
	}
	else
		;//树中存在该元素
	return p; 
}
void PreLeaves(PBTNODE t,int height)//先序遍历叶节点 
{
	if(t!=NULL)
	{
		if(t->left==NULL&&t->right==NULL)
		{
			printf("%d ",t->data);
			printf("%d\n",height+1);
		}
		PreLeaves(t->left,height+1);
		PreLeaves(t->right,height+1);
	}
}


