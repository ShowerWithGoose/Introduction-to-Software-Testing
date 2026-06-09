#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct node{
	int data;
	int high;
	struct node *left,*right;
}tree;
tree *head;
int n,t,l,i;
tree *code(tree *root , int t,int h){
	h++;
	if(root==NULL){
		root=(tree*)malloc(sizeof(tree));
		root->data=t;
		root->left=NULL;
		root->right=NULL;
		head=root;
		root->high=h;
	}
	else if(t>=root->data){
		root->right=code(root->right,t,h);
	}
	else if(t<=root->data){
		root->left=code(root->left,t,h);
	}
	return root;
}
void print(tree *root){
	if(root!=NULL){
		if(root->left==NULL&&root->right==NULL){
			printf("%d %d\n",root->data,root->high);
		}
		print(root->left);
		print(root->right);
	}
}
int main(){
	tree *root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
	    scanf("%d",&t);
		l=0;
		root=code(root,t,l);
	}
	print(root);
	return 0;
}



