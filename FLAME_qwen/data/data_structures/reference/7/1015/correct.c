#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct BTNode{
	int num;
	int dep;
	struct BTNode *left;
	struct BTNode *right;
}tree,*treep;
treep root=NULL;
void InsertBST(treep *t,int num,int dep);
void Inorder (treep t) {
	if(t!=NULL) {
		Inorder(t->left);
		if(t->left==NULL && t->right==NULL) {
			printf("%d %d\n",t->num,t->dep);
			
		}
		Inorder(t->right);
	}
}
int main() {
	int n,val;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&val);
		InsertBST(&root,val,1);
	} 
	Inorder(root);
	return 0;
}
void InsertBST(treep *t,int num,int dep) {
	if(*t==NULL) {
		*t = (treep)malloc(sizeof(treep));
		(*t)->left=(*t)->right=NULL;
		(*t)->num=num;
		(*t)->dep=dep;
		
	}
	else if(num<(*t)->num) {
		InsertBST(&((*t)->left),num,dep+1);
	}
	else {
		InsertBST(&((*t)->right),num,dep+1);
	}
	
}

