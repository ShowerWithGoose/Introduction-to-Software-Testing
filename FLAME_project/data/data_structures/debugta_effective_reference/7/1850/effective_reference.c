#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int num;
	struct node *lchild,*rchild;
}BTNode,*BTREE;

BTREE tree=NULL;

void INSERT(int x);
void print(BTREE t,int h);

int main(){
	int n,i,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		INSERT(x);
	}
	print(tree,1);
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
	BTREE q,p;
	q=tree;
	p=(BTREE)malloc(sizeof(BTNode));
	p->lchild=p->rchild=NULL;
	p->num=x;
	if(q==NULL){
		tree=p;
	}else{
		while(q->num<=x&&q->rchild!=NULL||q->num>x&&q->lchild!=NULL){
			if(q->num<=x)
				q=q->rchild;
			else
				q=q->lchild;
		}
		if(q->num<=x)
				q->rchild=p;
			else
				q->lchild=p;
	}
}

