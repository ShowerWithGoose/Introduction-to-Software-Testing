#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct treenode{
	struct treenode * lchild;
	struct treenode * rchild;
	int data;
	int depth;
}ROOT,*PROOT;

int n,dep;

PROOT insert(PROOT,int,int);
void traverse_easy(PROOT);

int main(){
	dep=1;
	scanf("%d",&n);
	int i,j,k,val;
	PROOT root;
	root=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&val);
//		printf("%d",val);
		root=insert(root,val,dep);
	}
	traverse_easy(root);
	return 0;
}
void traverse_easy(PROOT root){
	
		if(root->lchild!=NULL)
		traverse_easy(root->lchild);
		if(root->lchild==NULL&&root->rchild==NULL){
		printf("%d %d\n",root->data,root->depth);
	}
		if(root->rchild!=NULL)
		traverse_easy(root->rchild);
	
}

PROOT insert(PROOT root,int val,int dep){
	if(NULL==root){
		root=(PROOT)malloc(sizeof(ROOT));
		root->data=val;
		root->depth=dep;
//		printf("%d %d\n",root->data,root->depth);
		root->lchild=NULL;
		root->rchild=NULL;
//		return root;
	}
	else if(val<root->data){
		root->lchild=insert(root->lchild,val,dep+1);
//		return root;
	}
	else{
		root->rchild=insert(root->rchild,val,dep+1);
//		return root;
	}
	return root;
}

