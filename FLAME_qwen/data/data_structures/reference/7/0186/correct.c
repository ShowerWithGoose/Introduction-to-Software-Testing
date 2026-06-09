#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	int data;
	int height;
	struct node *lchild;
	struct node *rchild;
};
int c;
typedef struct node *ecd,ecs;
ecd insert(ecd p,int item){
	if(p==NULL){
		p=(ecd)malloc(sizeof(ecs));
		p->height=c;
		p->data=item;
		p->lchild=p->rchild=NULL;
	}
	else if(item<p->data){
		c++;
		p->lchild=insert(p->lchild,item);
	}
	else if(item>=p->data){
		c++;
		p->rchild=insert(p->rchild,item);
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
	ecd list,r;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		c=1;
		scanf("%d",&a);
		list=insert(list,a);
	}
	visit(list);
	return 0;
}

