#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include<ctype.h>
typedef struct node
{
	int data;
	int height;
	struct node *left,*right;
 } tree;
 tree *first;
 tree *insert(tree *root,int temp,int high);
 void print(tree *root);
int main()
{
	tree *root=NULL;
	int n,i,a,b;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		b=0;
		scanf("%d",&a);
		root=insert(root,a,b);
	}
	print(root);
return 0;
}
tree *insert(tree *root,int temp,int high){
	high++;
	if(root==NULL){
		root = (tree *)malloc(sizeof(tree));
		root->data=temp;
		root->left=NULL;
		root->right=NULL;
		first=root;
		root->height=high; 
	} else if(temp<root->data){
		root->left = insert(root->left, temp, high);
	} else if(temp>=root->data){
		root->right = insert(root->right, temp, high);
	}
	return root;
	}

void print(tree *root){
	if(root!=NULL){
		if((root->left)==NULL&&(root->right)==NULL){
			printf("%d %d\n",root->data,root->height);
		}
		print(root->left);
		print(root->right);
	}
}

