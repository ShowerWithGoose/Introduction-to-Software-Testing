#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct _Bst{
	int num;
	int Height;
	struct _Bst *lchild,*rchild; 
};
typedef struct _Bst Bst;
typedef struct _Bst *pBst;

int height=1;
pBst insertBst(pBst p,int item){
	if(p==NULL)
	{
		p=(pBst)malloc(sizeof(Bst));
		p->num=item;
		p->Height=height;
		height=1;
		p->lchild=p->rchild=NULL;
	}
	else if(item<p->num){
		height++;
		p->lchild=insertBst(p->lchild,item);
	}
	else{
		height++;
		p->rchild=insertBst(p->rchild,item);
	}
	return p;
}

void printbst(pBst q){
	if(q!=NULL){
		printbst(q->lchild);
		if(q->lchild==NULL && q->rchild==NULL){
			printf("%d ",q->num);
			printf("%d\n",q->Height);
		}
		printbst(q->rchild);
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	int i,data;
	pBst Root=NULL;
	for(i=0;i<N;i++){
		scanf("%d",&data);
		Root=insertBst(Root,data);
	}
	printbst(Root);
	return 0;
}



