#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

typedef struct treenode{
	int val;
	int depth;
	struct treenode *left;
	struct treenode *right;
}*treep;
treep root=NULL;
int depth=1;
void Sonnode(treep ptr);
void Insert_tree(treep *ptr,int ,int );
void fun(treep ptr);
int main(){
	int n,i,data;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		Insert_tree(&root,data,1);
	}
	Sonnode(root);
return 0;
}

void Visit(treep ptr)
{
	printf("%d %d\n",ptr->val,ptr->depth);
}

void Sonnode(treep p)//访问子节点 
{
	if(p!=NULL)
	{
		Sonnode(p->left);
		if((p->left==NULL) && (p->right==NULL))		Visit(p);
		Sonnode(p->right);
	}
}

void Insert_tree(treep *ptr,int num,int height){
	if(*ptr==NULL)
	{
		*ptr=(treep)malloc(sizeof(treep));
		(*ptr)->left=(*ptr)->right=NULL;
		(*ptr)->depth=height;
		(*ptr)->val=num;
	}
	else if(num<(*ptr)->val)
		Insert_tree(&((*ptr)->left),num,height+1);
	else
		Insert_tree(&((*ptr)->right),num,height+1);
}

