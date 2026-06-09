#include <stdio.h>
#include <stdlib.h>

typedef struct TN{
	int Item;
	struct TN *left;
	struct TN *right;
}TreeNode;

TreeNode *Insert(TreeNode *root,int InData);
void PrintLeaf(TreeNode *root,int height);

int main(){
	int num,i,InData;
	TreeNode *root=NULL;
	scanf("%d",&num);
	for(i=0;i<num;i++){
		scanf("%d",&InData);
		root=Insert(root,InData);
	}
	PrintLeaf(root,1);
	return 0;
}

TreeNode *Insert(TreeNode *root,int InData){
	if(!root){
		root=(TreeNode *)malloc(sizeof(TreeNode));
		root->Item=InData;
		root->left=root->right=NULL;
	}
	else{
		if(root->Item>InData) root->left=Insert(root->left,InData);
		else root->right=Insert(root->right,InData);
	}
	return root;
}

void PrintLeaf(TreeNode *root,int height){
	if(!root) return;
	if(root->left==NULL&&root->right==NULL) printf("%d %d\n",root->Item,height);
	if(root->left!=NULL) PrintLeaf(root->left,height+1);
	if(root->right!=NULL) PrintLeaf(root->right,height+1);
}

