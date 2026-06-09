#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define ll long long
#define eps 1e-6
#define MAX 1000005
typedef struct node{
	int data,deep;
	struct node *left,*right;
}*list;
list p=NULL,q=NULL,root=NULL;
list bst(list p,int item,int deep){
	if(p==NULL){
		p=(list)malloc(sizeof(struct node));
		p->data=item;
		p->deep=deep;
		p->left=p->right=NULL;
	}
	else if(item<p->data){
		p->left=bst(p->left,item,p->deep+1);
	}else{
		p->right=bst(p->right,item,p->deep+1);
	}
	return p;
}
void visit(list p){
	if(p->left==NULL&&p->right==NULL){
		printf("%d %d\n",p->data,p->deep);
	}
}
void postorder(list p){
	if(p!=NULL){
		postorder(p->left);
		postorder(p->right);
		visit(p);
	}
}

int main(){
	int n,i,item,t=1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&item);
		root=bst(root,item,t);
	}
	postorder(root);
	return 0;
}


