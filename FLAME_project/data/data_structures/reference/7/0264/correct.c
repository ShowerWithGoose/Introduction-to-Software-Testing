#include<stdio.h>
#include<stdlib.h>
typedef struct _tree{
	int data;
	struct _tree *lchild;
	struct _tree *rchild;
}tree;
tree* buildTree(tree *p,int x){
	if(p==NULL){
		p=(tree*)malloc(sizeof(tree));
		p->data=x;
		p->lchild=NULL;
		p->rchild=NULL;
	}
	else if(x<p->data)
		p->lchild=buildTree(p->lchild,x);
	else if(x<p->data)
		p->rchild=buildTree(p->rchild,x);
	else
		p->rchild=buildTree(p->rchild,x);
	return p;
}
void printTree(tree *root,int h){
	if(root!=NULL){
		if(root->lchild==NULL&&root->rchild==NULL){
			printf("%d %d\n",root->data,h);
		}
		printTree(root->lchild,h+1);
		printTree(root->rchild,h+1);
	}
	return;
}
int main(){
	int n,x,i;
	tree *root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		root=buildTree(root,x);
	}
	printTree(root,1);
	return 0;
}

