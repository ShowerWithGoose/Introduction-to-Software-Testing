#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct TreeNode* Tree;
struct TreeNode{
	int val,height;
	struct TreeNode *left,*right;
};

Tree CreateNode(int val,int height)
{
	Tree tmp=(Tree)malloc(sizeof(struct TreeNode));
	tmp->val=val;
	tmp->height=height;
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
}

Tree insert_height(Tree root,int val,int height)//初始为1 
{
	if(root==NULL){
		return CreateNode(val,height);
	}
	if(val<root->val){
		root->left=insert_height(root->left,val,root->height+1);
	}
	else{
		root->right=insert_height(root->right,val,root->height+1);
	}
	return root;
}

void printLeaf(Tree root)
{
	if(root->left==NULL&&root->right==NULL){//是叶子 
		printf("%d %d\n",root->val,root->height);
		return ;
	}
	if(root->left!=NULL) printLeaf(root->left);
	if(root->right!=NULL) printLeaf(root->right);
}

int main()
{
	Tree root=NULL;
	int n,val;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&val);
		root=insert_height(root,val,1);
	}
	printLeaf(root);
	return 0;
}

