#include <stdio.h>
#include <stdlib.h>

struct treenode{
	int data;
	int depth;
	struct treenode *left;
	struct treenode *right;
};
typedef struct treenode tree,*ptree;

void inorder(ptree p){
	if(p != NULL){
		inorder(p->left);
		if(p->left==NULL && p->right==NULL)
			printf("%d %d\n",p->data,p->depth);
		inorder(p->right);
	}
}

void insertbst(ptree *p,int n,int depth){
	if(*p == NULL){
		*p = (ptree)malloc(sizeof(ptree));
		(*p)->left = (*p)->right = NULL;
		(*p)->data = n;
		(*p)->depth = depth;
	}
	else if(n < (*p)->data){
		insertbst(&((*p)->left),n,depth+1);
	}
	else{
		insertbst(&((*p)->right),n,depth+1);
	}
}

int main() {
	int n,i,j,depth = 1;
	ptree root = NULL;
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d",&j);
		insertbst(&root,j,1);
	}
	inorder(root);
	return 0;
}

