#include<stdio.h>
#include<stdlib.h>
typedef struct _Bst{
	int height;
	int data;
	struct _Bst* lchild;
	struct _Bst* rchild;
}Bst,*pBst;
pBst CreatBst(pBst root,int data,int height){ //建立二叉树
	if(root==NULL){
		//开辟root结点
		root=(pBst)malloc(sizeof(Bst));
		root->data=data;
		root->lchild=NULL;
		root->rchild=NULL;
		root->height=height;
		return root;
	}
	else if(data<root->data){
		root->lchild=CreatBst(root->lchild,data,height+1);
	}
	else {
		root->rchild=CreatBst(root->rchild,data,height+1);
	}
	return root;
}
void printBst(pBst root){
	if(root==NULL) return;
	if(root->lchild==NULL&&root->rchild==NULL){
		printf("%d %d\n",root->data,root->height);
		return;
	}
	if(root->lchild) printBst(root->lchild);
	if(root->rchild) printBst(root->rchild);
}
int main()
{
	pBst BstRoot=NULL;
	int n,data;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&data);
		BstRoot=CreatBst(BstRoot,data,1);
	} //建立二叉树
	//遍历，前中后顺序都可以
	printBst(BstRoot);
	return 0;	
}

