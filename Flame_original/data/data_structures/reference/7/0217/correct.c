#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct Tree
{
	int base;
	int deep;
	struct Tree *left, *right;
} tree;
tree *f;
tree *build(tree *root, int t, int l){
	l++;
	if(root==NULL){
		root = (tree *)malloc(sizeof(tree));
		root->base=t;
		root->left=root->right=NULL;
		f=root;
		root->deep=l;
	}
	else if(t<root->base)
	root->left=build(root->left, t, l);
	else if(t>=root->base)
	root->right=build(root->right, t, l);
	return root;
}
void print(tree *root){
	if(root){
	if(!(root->left)&&!(root->right)){
	printf("%d %d\n", root->base, root->deep);
    }
	print(root->left);
	print(root->right);
    }
}
int main()
{
	int N,i,t;
	int l=0;
	tree *root=NULL;
	scanf("%d", &N);
	for(i=0;i<N;i++){
		scanf("%d ",&t);
		root=build(root, t, l);
	}
	print(root);
	return 0;
}



