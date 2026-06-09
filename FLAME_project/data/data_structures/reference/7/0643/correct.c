#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *lchild,*rchild;
};
typedef struct node BTNode;
typedef struct node* BTNodeptr;

BTNodeptr initTree(BTNodeptr t,int data){
	BTNodeptr p;
	if(t==NULL){
		p=(BTNodeptr)malloc(sizeof(BTNode));
		p->data=data;
		p->lchild=p->rchild=NULL;
		return p; 
	}
	else if(data<t->data){
		t->lchild=initTree(t->lchild,data);
	}
	else{
		t->rchild=initTree(t->rchild,data); 
	}
	return t;
}


void printLeafNode(BTNodeptr t,int height){
	if(t->lchild!=NULL){
		printLeafNode(t->lchild,height+1);
	}
	if(t->rchild!=NULL){
		printLeafNode(t->rchild,height+1);
	}
	if(t->lchild==NULL&&t->rchild==NULL){
		printf("%d %d\n",t->data,height);
	}
}


int main(){
	BTNodeptr t=NULL;
	int n,data,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		t=initTree(t,data);
	}
	printLeafNode(t,1);
	return 0;
}

