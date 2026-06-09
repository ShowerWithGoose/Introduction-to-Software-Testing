#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
typedef struct _num{
	int n;
	struct _num* lchild;
	struct _num* rchild;
}num, *Pnum;

void print(Pnum, int);//±éÀú´òÓ¡
Pnum create(Pnum, int);//½¨Ê÷ 

int main(){
	int i, j, k, m;
	Pnum root=NULL;
	scanf("%d", &k);
	for(i=0; i<k; i++){
		scanf("%d", &m);
		root=create(root, m);
		}
	print(root, 1);
	return 0;
}

void print(Pnum a, int h){
	if(a==NULL) return;
	if(a->lchild!=NULL) print(a->lchild, h+1);
	if(a->lchild==NULL&&a->rchild==NULL){
		printf("%d %d\n", a->n, h);
	}
	if(a->rchild!=NULL) print(a->rchild, h+1);
}

Pnum create(Pnum t, int v){
	if(t==NULL){
		t=(Pnum)malloc(sizeof(num));
		t->lchild=t->rchild=NULL;
		t->n=v;
		return t;
	}
	else if(v<t->n){
		t->lchild=create(t->lchild, v);
	}
	else{
		t->rchild=create(t->rchild, v);
	}
	return t; 
}


