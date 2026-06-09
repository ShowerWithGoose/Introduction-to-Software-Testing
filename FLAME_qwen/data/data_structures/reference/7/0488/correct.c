#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int num;
	struct node *lchild,*rchild;
}BTNode,*BTREE;

BTREE T=NULL;

void INSERT(int x);
void print(BTREE t,int h);

int main(){
	int n,i,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		INSERT(x);
	}
	print(T,1);
	return 0;
}

void print(BTREE t,int h){
	if(t->lchild==NULL&&t->rchild==NULL){
		printf("%d %d\n",t->num,h);
	}else{
		if(t->lchild!=NULL)
			print(t->lchild,h+1);
		if(t->rchild!=NULL)
			print(t->rchild,h+1);
	}
}

void INSERT(int x){
	BTREE p,q;
	p=T;
	q=(BTREE)malloc(sizeof(BTNode));
	q->lchild=q->rchild=NULL;
	q->num=x;
	if(p==NULL){
		T=q;
	}else{
		while(p->num<=x&&p->rchild!=NULL||p->num>x&&p->lchild!=NULL){
			if(p->num<=x)
				p=p->rchild;
			else
				p=p->lchild;
		}
		if(p->num<=x)
				p->rchild=q;
			else
				p->lchild=q;
	}
}

