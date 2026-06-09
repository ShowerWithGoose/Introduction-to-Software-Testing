#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	int num;
	int high;
	struct node *lchild;
	struct node *rchild;
};

typedef struct node Tree;
typedef struct node *Treep;

Treep root = NULL;

void Insert(Treep *t,int zhi,int depth)
{
	if(*t == NULL){
		(*t) = (Treep)malloc(sizeof(Tree));
		(*t)->lchild = (*t)->rchild = NULL; 
		(*t)->num = zhi;
		(*t)->high = depth;
	}
	else{
		if((*t)->num <= zhi)
			Insert(&((*t)->rchild),zhi,depth+1);
		else if((*t)->num > zhi)
			Insert(&((*t)->lchild),zhi,depth+1);
	}
}

void postorder(Treep t)
{
	if(t!=NULL){
		postorder(t->lchild);
		postorder(t->rchild);
		if(t->lchild == NULL && t->rchild == NULL)
			printf("%d %d\n",t->num,t->high);	
	}
}

int main()
{
	int n;
	int i,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&k);
		Insert(&root,k,1);
	}
	//printf("\n%d %d\n\n",root->num,root->high);
	postorder(root);
	return 0;
}

