#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	int x;
	int level;
	struct tree*parent;
	struct tree*left;
	struct tree*right;
}trees,*Trees;
Trees T;
void settree(int xi);
void build(int xi);
void search(Trees t);
void visit(Trees t);
int main(){
	int n;
	scanf("%d",&n);
	int xi;
	scanf("%d",&xi);
	settree(xi);
	n--;
	while(n--){
		scanf("%d",&xi);
		build(xi);
	}
	search(T);
	return 0;
}
void settree(int xi){
	T=(Trees)malloc(sizeof(trees));
	T->level=1;
	T->x=xi;
	T->parent=NULL;
	T->left=NULL;
	T->right=NULL;
}
void build(int xi){
	Trees p=T,q;
	while(p){
		if(xi>=p->x){
			q=p;
			p=p->right;
		}
		else {
			q=p;
			p=p->left;
		}
	}
	p=(Trees)malloc(sizeof(trees));
	p->parent=q;
	p->left=NULL;
	p->right=NULL;
	p->level=q->level+1;
	p->x=xi;
	if(xi>=q->x){
		q->right=p;
	}
	else {
		q->left=p;
	}
}
void search(Trees t){
	if(t!=NULL){
		visit(t);
		search(t->left);
		search(t->right);
	}
}
void visit(Trees t){
	if(t->left==NULL&&t->right==NULL){
		printf("%d %d\n",t->x,t->level);
	}
}


