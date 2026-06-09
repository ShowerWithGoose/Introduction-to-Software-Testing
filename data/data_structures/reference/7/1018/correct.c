#include<stdio.h>
#include<string.h> 
#include<stdlib.h>

typedef struct tree{
	int num;
	struct tree *left;
	struct tree *right;
}tree;
struct{
	tree (*node)[100];
	int top;
}treeStack;

tree *createLeave(int num, tree *parent);
void clear(tree *root);
void searchLeave(tree *root, int depth);

int main(){
tree *root;
int all, num;
root = (tree*)malloc(sizeof(tree));
root->left = NULL;
root->right = NULL;
scanf("%d",&all);
scanf("%d",&root->num);
for(int i=1;i<all;i++){
	scanf("%d",&num);
	createLeave(num,root);
}
searchLeave(root,1);

clear(root);
return 0;
} 

void searchLeave(tree *root, int depth){
	if(root->left == NULL && root->right == NULL){
		printf("%d %d\n",root->num,depth);
		return;
	}
	if(root->left != NULL){
		searchLeave(root->left,depth+1);
	}
	if(root->right != NULL){
		searchLeave(root->right,depth+1);
	}
}

void clear(tree *root){
	if(root->left == NULL && root->right == NULL){
//		printf("%d ",root->num);
		free(root);
		return;
	}
	if(root->left != NULL){
//		printf("toL %d\n",root->num);
		clear(root->left);
		root->left = NULL;
//		printf("BackFromLeft %d\n",root->num);
	}
	if(root->right != NULL){
//		printf("toR %d\n",root->num);
		clear(root->right);
		root->right = NULL;
//		printf("BackFromRight %d\n",root->num);
	}
	if(root->left == NULL && root->right == NULL){
//		printf("%d ",root->num);
		free(root);
		return;
	}
}

tree *createLeave(int num, tree *parent){
	tree *pi, *newLeave;
	pi = parent;
	if(num < pi->num){
		if(pi->left != NULL) newLeave = createLeave(num,pi->left);
		else{
			newLeave = (tree*)malloc(sizeof(tree));
			pi->left = newLeave;
			newLeave->left = NULL;
			newLeave->num = num;
			newLeave->right = NULL;
		}
	}
	else{
		if(pi->right != NULL) newLeave = createLeave(num,pi->right);
		else{
			newLeave = (tree*)malloc(sizeof(tree));
			pi->right = newLeave;
			newLeave->left = NULL;
			newLeave->num = num;
			newLeave->right = NULL;
		}
	}
	return newLeave;
}




















