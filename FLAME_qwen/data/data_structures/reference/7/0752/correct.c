#include <stdio.h>
#include <stdlib.h>
typedef struct NODE{
	int data;
	int depth;
	struct NODE *lchild;
	struct NODE *rchild;
}node,*nodeptr;
void InsertBST(int num,nodeptr root);
void DisplayLeaves(nodeptr root);
int main() {
	int n;
	scanf("%d",&n);
	int tempNum;
	scanf("%d",&tempNum);
	nodeptr tree=(nodeptr)malloc(sizeof(node));
	tree->data=tempNum;
	tree->depth=1;
	tree->lchild=NULL;
	tree->rchild=NULL;
	for(int i=2;i<=n;i++){
		scanf("%d",&tempNum);
		InsertBST(tempNum,tree);
	}
	DisplayLeaves(tree);
	return 0;
}
void DisplayLeaves(nodeptr root){
	if(root==NULL){
		return;
	}
	DisplayLeaves(root->lchild);
	if(root->lchild==NULL&&root->rchild==NULL){
		printf("%d %d\n",root->data,root->depth);
		return;
	}
	DisplayLeaves(root->rchild);
	return;
}
void InsertBST(int num,nodeptr root){
	if(num<root->data){
		if(root->lchild==NULL){
			root->lchild=(nodeptr)malloc(sizeof(node));
			root->lchild->data=num;
			root->lchild->depth=root->depth+1;
			root->lchild->lchild=NULL;
			root->lchild->rchild=NULL;
			return;
		}else{
			InsertBST(num,root->lchild);
		}
	}else{
		if(root->rchild==NULL){
			root->rchild=(nodeptr)malloc(sizeof(node));
			root->rchild->data=num;
			root->rchild->depth=root->depth+1;
			root->rchild->lchild=NULL;
			root->rchild->rchild=NULL;
			return;
		}else{
			InsertBST(num,root->rchild);
		}
	}
}





















