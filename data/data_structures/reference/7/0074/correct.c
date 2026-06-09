#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct BSTree{
	struct BSTree *lchild;
	int value;
	int depth;
	struct BSTree *rchild;
};
typedef struct BSTree *bst; 
int i,j,k,n;
bst p,q;
bst root=NULL;
bst creatBST(int n){
	for(i=0;i<n;i++){
		p=(bst)malloc(sizeof(bst));
		p->lchild=NULL;p->rchild=NULL; 
		scanf("%d",&p->value);
		if(root==NULL){
			p->depth=1;
			root=p;
			continue;
		}else{
			q=root;
			while(1){
				if(p->value<q->value){
					if(q->lchild==NULL){
						q->lchild=p;
						p->depth=q->depth+1;
						break;
					}else{
						q=q->lchild;
					}
				}else if(p->value>=q->value){
					if(q->rchild==NULL){
						q->rchild=p;
						p->depth=q->depth+1;
						break;
					}else{
						q=q->rchild;
					}
				}				
			}
		}
	}
}
bst printBST(bst root){
	if(root==NULL){
		return NULL;
	}
	if(root->lchild==NULL&&root->rchild==NULL){
		printf("%d %d\n",root->value,root->depth);
	}
	printBST(root->lchild);
	printBST(root->rchild);
} 
int main(){
	scanf("%d",&n);
    creatBST(n);
	printBST(root);
	return 0;
}

