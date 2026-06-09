#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	int data;
	struct tree *l;
	struct tree *r;
} BT;
BT *insert(int x,BT *BST){
	if(!BST){
		BST=(BT*)malloc(sizeof(BT));
		BST->data=x;
		BST->l=BST->r=NULL;
	}
	else if(x<BST->data) BST->l=insert(x,BST->l);
	else if(x>=BST->data) BST->r=insert(x,BST->r);
	return BST;
}
void leaf(BT *l,int k){
	if(l){
		k++;
		if(!l->l&&!l->r) printf("%d %d\n",l->data,k);
		leaf(l->l,k);
		leaf(l->r,k);
	}
}
int main(){
	int N,i,j,k=0,l;
	BT *BST=NULL;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&j);
		BST=insert(j,BST);
	}
	leaf(BST,k);
}

