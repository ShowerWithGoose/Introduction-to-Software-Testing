#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct tnode{
	int high;
	int data;
	struct tnode* lchild;
	struct tnode* rchild;
};
int h=1;
struct tnode* root=NULL;
int n;
int num;
struct tnode* insert(struct tnode*,int);
void inorder(struct tnode*);
int main(){
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&num);
		root=insert(root,num);
		h=1;
	}
	inorder(root);
}
struct tnode* insert(struct tnode* t,int num){
	if(t==NULL){
		t=(struct tnode*)malloc(sizeof(struct tnode));//勿漏指针空间开辟 
		t->data=num;
		t->lchild=NULL;
		t->rchild=NULL;
		t->high=h;
	}
	else if(num>=t->data){//注意相等 
		h++;
		t->rchild=insert(t->rchild,num);
	}
	else if(num<t->data){
		h++;
		t->lchild=insert(t->lchild,num);
	}
	return t;//勿漏返回值 
}
void inorder(struct tnode* t){
	if(t!=NULL){
		inorder(t->lchild);
		if(t->lchild==NULL && t->rchild==NULL) printf("%d %d\n",t->data,t->high);
		inorder(t->rchild);
	}
	return;
}

