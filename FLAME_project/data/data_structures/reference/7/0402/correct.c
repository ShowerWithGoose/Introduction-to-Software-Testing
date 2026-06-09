#include <stdio.h>
#include <stdlib.h>
struct Treenode{
	int data;
	struct Treenode *left;
	struct Treenode *right;
	int depth;
};
int n,data,depth=1;
struct Treenode *root=NULL;
void CreateBST(struct Treenode** root,int data,int depth){
	if((*root)==NULL){
		*root=(struct Treenode *)malloc(sizeof(struct Treenode));
		(*root)->data=data;
		(*root)->depth=depth;
		(*root)->left=(*root)->right=NULL;
	}
	else if(data<(*root)->data){
		CreateBST(&((*root)->left),data,depth+1);
	}
	else{
		CreateBST(&((*root)->right),data,depth+1);
	}
}
void inorder(struct Treenode *root){
	if(root==NULL) return;
	inorder(root->left);
	if(root->left==NULL&&root->right==NULL) printf("%d %d\n",root->data,root->depth);
	inorder(root->right);
}
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&data);
		CreateBST(&root,data,depth);
	}
	inorder(root);
	return 0;
}

