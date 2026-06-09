#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct NODE {
	int data;
	int depth;
	struct NODE *left;
	struct NODE *right;
}node;

node *AddNode(int ,node *,int );

void VisitData(node *);

int main(){
	
	int n,tmp;
	scanf("%d",&n);
	node *root=NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		root=AddNode(tmp,root,0);
	}
	
	VisitData(root);
	
	return 0;
}

node *AddNode(int data,node *root,int depth){
	
	if(root==NULL){
		root=(node *)malloc(sizeof(node ));
		root->data=data;
		root->left=root->right=NULL;
		root->depth=++depth;
	}
	else if(data<root->data){
		root->left=AddNode(data,root->left,++depth);
	}
	else{
		root->right=AddNode(data,root->right,++depth);
	}
	
	return root;
}

void VisitData(node *root){
	
	node *pt=root;
	if(pt->left!=NULL){
		VisitData(pt->left);
	}
	if(pt->left==NULL&&pt->right==NULL){
		printf("%d %d\n",pt->data,pt->depth);
	}
	if(pt->right!=NULL){
		VisitData(pt->right);
	}
	
	return ;
}

