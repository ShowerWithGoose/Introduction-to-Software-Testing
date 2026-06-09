#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	int high;
	struct node*left,*right;
}Tree; 
Tree *creattree(Tree*root,int temp,int len);
void print(Tree*root);

int main(){
	Tree *root=NULL;
	int n;int temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		int len=0;
		root=creattree(root,temp,len);
	}
	print(root);
	
	

	
	return 0;
} 
Tree *creattree(Tree*root,int temp,int len){
	len++;
	if(root==NULL){
		root=(Tree*)malloc(sizeof(Tree));
		root->data=temp;
		root->left=root->right=NULL;
	    root->high=len;
	    
	}
	else if(temp<root->data){
		root->left=	creattree(root->left,temp,len);
	}
	else if(temp>=root->data){
			root->right=creattree(root->right,temp,len);
		}
	return root;
} 
void print(Tree*root){
	if (root){
		if((root->left==NULL)&&(root->right==NULL)){
	         printf("%d %d\n",root->data,root->high);
	
		}
		print(root->left);
		print(root->right);}
}

