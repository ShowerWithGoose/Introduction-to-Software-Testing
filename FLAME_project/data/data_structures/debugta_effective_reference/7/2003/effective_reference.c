#include <stdio.h>//二叉树查找树构造,打印叶节点data和深度
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define TOPLAYER 1
typedef struct BstNode{
	int data;
	struct BstNode *left,*right;
}BstNode,*BstNodePtr;
BstNodePtr insBst(BstNodePtr root,int data);
void printLeafHeight(BstNodePtr root,int height);
//int leaf=0;
int main()
{
	int n,data;
	BstNodePtr root=NULL;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&data);
		root=insBst(root,data);
	}
	if (root!=NULL)
		printLeafHeight(root,TOPLAYER);
	return 0;
}
BstNodePtr insBst(BstNodePtr root,int data){//构造左小右大的二叉查找树,递归
	if (root==NULL){
		root=(BstNodePtr)malloc(sizeof(BstNode));
		root->data=data;
		root->left=NULL;
		root->right=NULL;
	}
	else if(data<root->data)
		root->left=insBst(root->left,data);
	else
		root->right=insBst(root->right,data);
	return root;
}
void printLeafHeight(BstNodePtr root,int height){//后续遍历,打印叶节点和其高度,返回
	if (root->left!=NULL)
		printLeafHeight(root->left,1+height);
	if (root->right!=NULL)
		printLeafHeight(root->right,1+height);
	if (root->left==NULL && root->right==NULL){
		printf("%d %d\n",root->data,height);
//		leaf++;	
	}
}



