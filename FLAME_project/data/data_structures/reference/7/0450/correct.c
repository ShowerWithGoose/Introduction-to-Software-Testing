#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Treenode{
	int data;
	struct Treenode *left;
	struct Treenode *right;
	int depth;
}Tree;

Tree* root=NULL;

void Visit(Tree* t){
	printf("%d %d\n",t->data,t->depth);
}

void Insert(Tree** t,int num,int d){
	if((*t)==NULL){
		(*t)=(Tree*)malloc(sizeof(Tree));
		(*t)->data=num;	(*t)->depth=d;
		(*t)->left = (*t)->right =NULL; 	
	}
	else if(num<(*t)->data){
		Insert(&(*t)->left,num,d+1);
	}
	else if(num>=(*t)->data){
		Insert(&(*t)->right,num,d+1);
	}
}

void Preorder(Tree* t){
	if(t==NULL) return;
	if(t->left ==NULL&&t->right ==NULL) Visit(t);
	Preorder(t->left);
	Preorder(t->right);	
}

int main()
{
	int n,i,num;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&num);
		Insert(&root,num,1);
	}
	Preorder(root);
	
	return 0;
}

