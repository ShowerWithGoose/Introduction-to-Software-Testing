#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *lchild,*rchild;
	int depth;
}BTNODE,*BTREE;

int K[10000];




BTREE INSERTBST(BTREE T,int item){
	BTREE p,q;
	p = (BTREE)malloc(sizeof(BTNODE));
	p->data = item;
	p->lchild = NULL;
	p->rchild = NULL;
	if(T == NULL)
		T = p;
	else{
		q = T;
		while(1)
			if(item<q->data)
				if(q->lchild != NULL){
					q = q->lchild;
				}
					
				else{
					q->lchild = p;
					q->lchild->depth = q->depth + 1;
					break;
				}
			else
				if(q->rchild != NULL){
					q = q->rchild;
				}
					
				else{
					q->rchild = p;
					q->rchild->depth = q->depth + 1;
					break;
				}
	}
	return T;
}

void PREORDER(BTREE T){
	if(T != NULL){
		if(T->lchild == NULL&&T->rchild == NULL)
			printf("%d %d\n",T->data,T->depth + 1);
		PREORDER(T->lchild);
		PREORDER(T->rchild);
	}
}

int main(){
	int n;
	BTREE T = NULL;
	scanf("%d",&n);
	int i;
	for(i = 0;i<n;i++){
		scanf("%d",&K[i]);
		T = INSERTBST(T,K[i]);
	}
	PREORDER(T);
	return 0;
}



