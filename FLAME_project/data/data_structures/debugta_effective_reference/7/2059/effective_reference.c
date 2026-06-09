#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	int data;
	int height;
	struct node *lchild;
	struct node *rchild;
};
int shendu;
typedef struct node *ecd,ecs;
ecd insert(ecd p,int a){
	if(p==NULL){
		p=(ecd)malloc(sizeof(ecs));
		p->height=shendu;
		p->data=a;
		p->lchild=p->rchild=NULL;
	}
	else if(a<p->data){
		shendu++;
		p->lchild=insert(p->lchild,a);
	}
	else if(a>=p->data){
		shendu++;
		p->rchild=insert(p->rchild,a);
	}
	return p;
}
void visit(ecd t){
	if(t!=NULL){
		visit(t->lchild);
		visit(t->rchild);
		if(t->lchild==NULL&&t->rchild==NULL) printf("%d %d\n",t->data,t->height);
	}
}
int main(){
	int n,i,a;
	ecd root,r;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		shendu=1;
		scanf("%d",&a);
		root=insert(root,a);
	}
	visit(root);
	return 0;
}

