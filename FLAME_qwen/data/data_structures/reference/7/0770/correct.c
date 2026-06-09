#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
	int data;
	int height;
	struct tree *l, *r, *parent;	
}Tnode;
void getnode(int);
void mid(Tnode*);
void visit(Tnode*);
Tnode *root;
int main(){
	root=(Tnode*)malloc(sizeof(Tnode));
	root->l=NULL;	root->r=NULL;	root->height=1;	root->parent=NULL;	root->data=-1;
	int n, val;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &val);
		getnode(val);
	}
	mid(root);
	
	return 0;
} 
void getnode(int a){
	if(-1 == root->data){	//get the root node
		root->data=a;	return;
	}
	Tnode *r=root, *add=(Tnode*)malloc(sizeof(Tnode));
	add->l=NULL;	add->r=NULL;	add->data=a;
	while(r!=NULL){
		if(a<r->data){
			if(r->l==NULL){
				r->l=add;	add->parent=r;	add->height=r->height+1;
				return;
			}
			r=r->l;
		}
		else if(a>=r->data){
			if(r->r==NULL){
				r->r=add;	add->parent=r;	add->height=r->height+1;
				return;
			}	
			r=r->r;			
		}
	}
}
void mid(Tnode *x){
	if(x==NULL)		return;
	mid(x->l);	visit(x);	mid(x->r);
}
void visit(Tnode *a){
	if(a->l==NULL && a->r==NULL)	printf("%d %d\n", a->data, a->height);
}
//创建，中序访问（无孩子就输出） 



