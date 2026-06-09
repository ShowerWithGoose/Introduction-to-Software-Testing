#include<stdio.h>
#include<stdlib.h>

typedef struct BitNode {
	int data;
	int high;
	struct BitNode *lchild,*rchild;
} BitNode;
typedef BitNode* BiTree;

BiTree Buildtree();
void CreateNode(BiTree,int);
BiTree PrintTree(BiTree);

int main() {
	int n,i,k;
	scanf("%d",&n);
	BiTree T;
	T=Buildtree();
	for(i=0;i<n-1;i++){
		scanf("%d",&k);
		CreateNode(T,k);
	}
	PrintTree(T);
	return 0;
}

BiTree Buildtree() {
	BiTree p;
	p=(BiTree)malloc(sizeof(BitNode));
	int n;
	scanf("%d",&n);
	p->data=n;
	p->high=1;
	p->lchild=NULL;
	p->rchild=NULL;
	return p;
}

void CreateNode(BiTree T,int n) {
	BiTree p;
	if(n>=T->data) {
		if(T->rchild==NULL) {
			p=(BiTree)malloc(sizeof(BitNode));
			T->rchild=p;
			p->data=n;
			p->high=T->high+1;
			p->lchild=NULL;
			p->rchild=NULL;
		} else {
			CreateNode(T->rchild,n);
		}

	} else if(n<T->data) {
		if(T->lchild==NULL) {
			p=(BiTree)malloc(sizeof(BitNode));
			T->lchild=p;
			p->data=n;
			p->high=T->high+1;
			p->lchild=NULL;
			p->rchild=NULL;
		} else {
			CreateNode(T->lchild,n);
		}
	}
}

BiTree PrintTree(BiTree T){
	if(T==NULL){
		return NULL;
	}
	if(T->lchild==NULL&&T->rchild==NULL){
		printf("%d %d\n",T->data,T->high);
	}
	PrintTree(T->lchild);
	PrintTree(T->rchild);
	return NULL;
}

