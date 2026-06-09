#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	int high;
	struct node *lift,*right;
} tree;
tree *head;
tree *insertbst(tree *root,int temp,int len){
	len++;
	if(root==NULL){
		root=(tree*)malloc(sizeof(tree));
		root->lift=NULL;
		root->right=NULL;
		root->data=temp;
		head=root;
		root->high=len;
	}
	else if(temp<root->data)
		root->lift=insertbst(root->lift,temp,len);
	else if(temp>=root->data)
		root->right=insertbst(root->right,temp,len);
		return root;
}
void print(tree *root){
	if(root){
		if(root->lift==NULL&&root->right==NULL){
			printf("%d %d\n",root->data,root->high);
		}
		print(root->lift);
		print(root->right);
	}
}
int main(){
	int n,temp,i,len=0;
	tree *root;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&temp);
		root=insertbst(root,temp,len);
	}
	print(root);
}

