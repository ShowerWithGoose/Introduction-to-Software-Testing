#include<stdio.h>
#include<string.h>
#include<math.h>
typedef struct tree{
	int num;
	int h;
	struct tree *lchild;
	struct tree *rchild;
}Tree;
Tree *first;
int h=1;
Tree *set(Tree *root,int count,int len){
	len++;
	if(root==NULL){
		root=(Tree*)malloc(sizeof(Tree));
		root->num=count;
		root->lchild=root->rchild=NULL;
		first=root;
		root->h=len;
	}
	else if(count<root->num){
		root->lchild=set(root->lchild,count,len);
	}
	else if(count>=root->num){
		root->rchild=set(root->rchild,count,len);
	}
	return root;
}
void printTree(Tree *root){
	if(root!=NULL){
		if(root->lchild==NULL&&root->rchild==NULL){
			printf("%d %d\n",root->num,root->h);
		}
		printTree(root->lchild);
		printTree(root->rchild);
	}
}
int main(){
    Tree *root=NULL;
	int n,i=0,len=0,count;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&count);
		root=set(root,count,len);
	}
	printTree(root);
}


