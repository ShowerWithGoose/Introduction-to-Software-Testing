#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *lchild,*rchild;
	int high;
}BTNODE,*BTREE;

int data[10000];




BTREE INSERTBST(BTREE root,int item){
	BTREE p,q;
	p = (BTREE)malloc(sizeof(BTNODE));
	p->data = item;
	p->lchild = NULL;
	p->rchild = NULL;
	if(root == NULL)
		root = p;
	else{
		q = root;
		while(1)
			if(item<q->data)
				if(q->lchild != NULL){
					q = q->lchild;
				}
					
				else{
					q->lchild = p;
					q->lchild->high = q->high + 1;
					break;
				}
			else
				if(q->rchild != NULL){
					q = q->rchild;
				}
					
				else{
					q->rchild = p;
					q->rchild->high = q->high + 1;
					break;
				}
	}
	return root;
}

void PREORDER(BTREE root){
	if(root != NULL){
		if(root->lchild == NULL&&root->rchild == NULL)
			printf("%d %d\n",root->data,root->high + 1);
		PREORDER(root->lchild);
		PREORDER(root->rchild);
	}
}

int main(){
	int n;
	BTREE root = NULL;
	scanf("%d",&n);
	int i;
	for(i = 0;i<n;i++){
		scanf("%d",&data[i]);
		root = INSERTBST(root,data[i]);
	}
	PREORDER(root);
	return 0;
}



