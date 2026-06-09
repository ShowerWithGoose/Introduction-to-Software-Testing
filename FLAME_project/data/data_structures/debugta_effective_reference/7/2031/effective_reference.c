#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
	int data;
	struct _node *right,*left;
}Node;
Node* establish(Node*root,int data){
	Node*p=(Node*)malloc(sizeof(Node));
	if(root==NULL){
		root=p;
		root->data=data;
		root->left=NULL;
		root->right=NULL;
	}
	else if(data<root->data){
		root->left=establish(root->left,data);
	}
	else if(data>=root->data)
	root->right=establish(root->right,data);
	return root;
}
void print(Node*root,int height){
	if(root->left!=NULL){
		print(root->left,height+1);
	}
	 if(root->right!=NULL){
		print(root->right,height+1);
	}
	if(root->left==NULL&&root->right==NULL){
		printf("%d %d\n",root->data,height);
	} 
}
int main()
{
	Node*root=NULL;
	int data,n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		root=establish(root,data);
	}
	print(root,1);
	return 0;
	}

