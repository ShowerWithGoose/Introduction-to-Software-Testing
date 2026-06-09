#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node{
	int data; 
	int height; 
	struct node *left,*right;
}Tree; 
Tree *setup(Tree *root,int temp,int num);
void result(Tree *root,int max);
int main(){
	Tree *root=NULL;
	int n,temp;
	int num; 
	int max=0;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&temp);
		num=0;
		root=setup(root,temp,num);
		if(num>max) max=num;
	}
	result(root,max);
	return 0;
}
Tree *setup(Tree *root,int temp,int num){
	num++;
	if(root==NULL){
		root=(Tree*)malloc(sizeof(Tree));
		root->data=temp;
		root->left=NULL;
		root->right=NULL;
		root->height=num;
	}
	else if(temp<root->data){
		root->left=setup(root->left,temp,num);
	}
	else if(temp>=root->data){
		root->right=setup(root->right,temp,num);
	}
	return root;
}

void result(Tree *root,int max){
	if(root){
		if(((root->left)==NULL)&&((root->right)==NULL)){
			printf("%d %d\n",root->data,root->height);
		}
		result(root->left,max);
		result(root->right,max);
	}
} 

