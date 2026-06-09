#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct TREE {
	int number;//储存数值
	struct TREE *left;//左子树
	struct TREE*right;//右子树
	int depth;//储存深度
}*tree;//建立结点
int num,i,n,depth=1;
tree root=NULL;

void search(tree t)//访问叶子结点
{
	if(t!=NULL){
		search(t->left);//递归
		if(t->left==NULL && t->right==NULL)
				printf("%d %d\n",t->number,t->depth);// 访问t指的叶子结点 
		search(t->right);
	}
}

void build(tree *t,int num,int depth){
	if(*t==NULL)
	{
		*t=(tree)malloc(sizeof(tree));
		(*t)->left=(*t)->right=NULL;
		(*t)->number=num;
		(*t)->depth=depth;
	}
	else if(num<(*t)->number)//现在数值小于当前数值，建立左子树
	{
		build(&((*t)->left),num,depth+1);
	} 
	else//现在数值大于当前数字，建立右子树递归
	{
		build(&((*t)->right),num,depth+1);
	} 
}//构造树，左节点<树节点<右节点

int main()
{	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		build(&root,num,1);
	}
	search(root);
	return 0;
}



