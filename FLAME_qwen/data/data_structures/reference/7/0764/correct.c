#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left,*right;
}lnode,*linklist;
linklist insettree(linklist p,int item);
void print(linklist t,int deep);
int main(){
	linklist root;
	root=(linklist)malloc(sizeof(lnode));
	root=NULL;
	int n,item,deep=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&item);
		root=insettree(root,item);
	}
	print(root,deep);
	return 0;
} 
linklist insettree(linklist p,int item){
	if(p==NULL){
		p=(linklist)malloc(sizeof(lnode));
		p->data=item;
		p->left=NULL;
		p->right=NULL;
	}
	else if(item>=p->data)
		p->right=insettree(p->right,item);
	else
		p->left=insettree(p->left,item);
	return p;
	}
void print(linklist t,int deep){
	if(t->left!=NULL&&t->right!=NULL){
		deep++;
		print(t->left,deep);
		print(t->right,deep);
	}
	else if(t->left==NULL&&t->right!=NULL){
		deep++;
		print(t->right,deep);
	}
	else if(t->right==NULL&&t->left!=NULL){
		deep++;
		print(t->left,deep);
	}
	else 
		printf("%d %d\n",t->data,deep);

}

