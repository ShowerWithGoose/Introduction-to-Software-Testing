#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct BTNode{
	int num;
	int high;
	struct BTNode *left;
	struct BTNode *right;
}tree,*treep;
treep T=NULL;
void InsertBST(treep *t,int num,int high);
void Inorder (treep t) {
	if(t!=NULL) {
		Inorder(t->left);
		if(t->left==NULL && t->right==NULL) {
			printf("%d %d\n",t->num,t->high);
			
		}
		Inorder(t->right);
	}
}
int main() {
	int n,num;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&num);
		InsertBST(&T,num,1);
	} 
	Inorder(T);
	return 0;
}
void InsertBST(treep *t,int num,int high) {
	if(*t==NULL) {
		*t = (treep)malloc(sizeof(treep));
		(*t)->left=(*t)->right=NULL;
		(*t)->num=num;
		(*t)->high=high;
		
	}
	else if(num<(*t)->num) {
		InsertBST(&((*t)->left),num,high+1);
	}
	else {
		InsertBST(&((*t)->right),num,high+1);
	}
	
}

