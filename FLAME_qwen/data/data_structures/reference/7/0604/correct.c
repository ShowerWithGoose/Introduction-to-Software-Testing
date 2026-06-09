#include<stdio.h>
#include<stdlib.h>
struct tree{
	int data;
	int height;
	struct tree *left;
	struct tree *right;
};
struct tree *build(struct tree *root,int a,int height){
	struct tree *q;
	q=(struct tree *)malloc(sizeof(struct tree));
	q->data=a;q->height=height;
	q->left=NULL;q->right=NULL;
	if(root==NULL) root=q;
	else if(q->data<root->data) root->left=build(root->left,a,height+1);
	else root->right=build(root->right,a,height+1);
	return root;
}
void print(struct tree *root){
	if(root!=NULL){
		print(root->left);
		if(root->left==NULL&&root->right==NULL) printf("%d %d\n",root->data,root->height);
		print(root->right);
	}
}
int main(){
	int n,a;
	struct tree *root=NULL;
	scanf("%d",&n);
	while(n--){
	scanf("%d",&a);
	root=build(root,a,1);}
	print(root);
}

