#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
typedef struct node{
	int data;
	int height;
	struct node *lchild,*rchild;
}tree;

tree *first; 
tree *root=NULL;

tree *leaf(tree *root,int num,int high){
	high++;
	if(root==NULL){//新建节点 
		root=(tree*)malloc(sizeof(tree));
		root->data=num;
		root->lchild=root->rchild=NULL;
		first=root;
		root->height=high;
	}
	else if(num<root->data){//小于进左子树 
		root->lchild=leaf(root->lchild,num,high);
	}
	else if(num>=root->data){//大于等于进右子树 
		root->rchild=leaf(root->rchild,num,high);
	}
	return root;
} 

void printTree(tree *root){
	if(root!=NULL){
		if((root->lchild==NULL)&&(root->rchild==NULL)){
			printf("%d %d\n",root->data,root->height);
		} 
		printTree(root->lchild);
		printTree(root->rchild);
	}
}

int main(){
	int n,num,i,high;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		high=0;
		scanf("%d",&num);
		root=leaf(root,num,high);
	}
	printTree(root);
	return 0;
}

