#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
typedef struct node{
	struct node *left;
	struct node *right;
	int num;
	int height; 
}tree;
tree *p;
tree *create(tree *root,int num,int high);
void print(tree *root);
int main(){
	tree *root=NULL;
	int n,i,high,temp;
	scanf("%d\n",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&temp);
		high=0;
		root=create(root,temp,high);
	} 
	print(root);
	return 0;
} 
tree *create(tree *root,int temp,int high){
	high++;
	if(root==NULL){
		root=(tree *)malloc(sizeof(tree));
		root->num=temp;
		root->left=NULL;
		root->right=NULL;
		p=root;
		root->height=high;
	}else if(temp<root->num){
		root->left=create(root->left,temp,high);
	}else{
		root->right=create(root->right,temp,high);
	}
	return root;
}
void print(tree *root)
{
    if (root)
    {
        if (!(root->left) && !(root->right))
        {
            printf("%d %d\n", root->num, root->height);
        }
        print(root->left);
        print(root->right);
    }
}

