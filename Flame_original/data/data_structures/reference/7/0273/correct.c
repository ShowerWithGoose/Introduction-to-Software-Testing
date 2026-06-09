#include<stdio.h>
#include<malloc.h>
struct node{
	int n;
	int lawer;
	struct node *lchild,*rchild;
};
typedef struct node function,*btnode;
btnode insert(btnode p,int x,int l){
	if(p==NULL){
		p=(btnode)malloc(sizeof(function));
		p->n=x;
		p->lawer=l+1;
		p->lchild=p->rchild=NULL;
	}
	else if (x<p->n) p->lchild=insert(p->lchild,x,p->lawer);
	else if (x>=p->n) p->rchild=insert(p->rchild,x,p->lawer);
	return p;
}
int visit(btnode p){
	if(p==NULL) return 0;
	if(p->lchild==NULL && p->rchild==NULL) printf("%d %d\n",p->n,p->lawer);
	else {
		visit(p->lchild);
		visit(p->rchild);
	}
}
int main(){
	int i,m,x;
	btnode root=NULL;
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d",&x);
		root=insert(root,x,0);
	}
	visit(root);
	return 0;
} 

