#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct bst{
	int data;
	struct bst *left,*right;
};
struct bst*insNode(struct bst*root,int data);
void printleaf(struct bst*root,int hight);
int main(){
	int n,data,i;
	struct bst*root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		root=insNode(root,data);
	}
	printleaf(root,1);
	return 0;
}
//创建一棵二叉树
struct bst*insNode(struct bst*root,int data){
	struct bst *p;
	if(root==NULL){
		p=(struct bst*)malloc(sizeof(struct bst));
		p->data=data;
		p->left=p->right=NULL;
		return p;
	}
	else if(data<root->data){
		root->left=insNode(root->left,data);
	}
	else {
		root->right=insNode(root->right,data);
	}
	return root;
}
//打印出叶节点及深度
void printleaf(struct bst*root,int hight) {
  if(root->left!=NULL){
		printleaf(root->left,hight+1);
		
	}
	if(root->right!=NULL){
		printleaf(root->right,hight+1);
	}
	if((root->left==NULL)&&(root->right==NULL)){
		printf("%d %d\n",root->data,hight);

	}
}
 

