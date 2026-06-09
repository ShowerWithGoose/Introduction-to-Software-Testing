#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXLINE 1024

struct bst{
	int num;
	int depth;
	struct bst *parent;
	struct bst *lchild;
	struct bst *rchild;
}; 

void inorder(struct bst *p);
struct bst* insert(struct bst *q,struct bst *p);

int main(){
	int n;
	int i,j,k;
	struct bst *p,*q;
	struct bst *root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&k);
		p=(struct bst*)malloc(sizeof(struct bst));
		p->num=k;
		p->depth=1;
		p->lchild=p->rchild=p->parent=NULL;
		if(root==NULL){
			//p->depth=1;
			root=p;	
		}
		else root=insert(root,p);	
	}
	inorder(root);

	return 0;
}
struct bst* insert(struct bst *q,struct bst *p){
	struct bst *k,*m;
	if(q==NULL) q=p;
	else{
		p->depth++;
		if(p->num<q->num)
	       q->lchild=insert(q->lchild,p);
    	else
    	    q->rchild=insert(q->rchild,p);
	}
	
	
	return q;
}
void inorder(struct bst *p){
	if(p!=NULL){
		inorder(p->lchild);
		if(p->lchild==NULL&&p->rchild==NULL)
		    printf("%d %d\n",p->num,p->depth);
		inorder(p->rchild);
		
	}
}









