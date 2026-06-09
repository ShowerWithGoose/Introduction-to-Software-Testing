#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int num,depth;
	struct node *lchild,*rchild;
}BTNode,*BTNodep;
int d=1;
BTNodep insertBST(BTNodep p,int m){
	if(p==NULL){
		p=(BTNodep)malloc(sizeof(BTNode));
		p->num=m;
		p->lchild=NULL;
		p->rchild=NULL;
	}
	else if(m<p->num)
		p->lchild=insertBST(p->lchild,m);
	else if(m>=p->num)
		p->rchild=insertBST(p->rchild,m); 
	return p;
}
void visit(BTNodep p){
		if(p->lchild){d++;
		visit(p->lchild);
		}
		if(p->lchild==NULL&&p->rchild==NULL){
			printf("%d %d\n",p->num,d);
		}
		if(p->rchild){
		d++;
		visit(p->rchild);}
		d--;
		
	
}
int main(){
	
	
	int n,i,m,d=1;
	scanf("%d",&n);
	scanf("%d",&m);
	BTNodep root=(BTNodep)malloc(sizeof(BTNode));
		root->num=m;
		root->lchild=NULL;
		root->rchild=NULL;
	for(i=1;i<n;i++){
		scanf("%d",&m);
		insertBST(root,m);
	}
	visit(root);
	return 0;
}

