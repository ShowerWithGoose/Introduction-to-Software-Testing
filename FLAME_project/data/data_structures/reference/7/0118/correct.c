#include<stdio.h>
typedef struct node{
	int high;
	int num;
	struct node *lchild;
	struct node *rchild;
}Node,*Lnode;
Lnode Btree,head;
int insert(int);
void print(Lnode);

int main(){
	int n,x,i;
	scanf("%d",&x);
	scanf("%d",&n);
 	Btree=(Lnode)malloc(sizeof(Node));
 	Btree->lchild=NULL;
	Btree->rchild=NULL;
	Btree->num=n;
	Btree->high=1;
 	head=Btree;
	for(i=1;i<x;i++){
		scanf("%d",&n);
		Btree=(Lnode)malloc(sizeof(Node));
		Btree->lchild=NULL;
		Btree->rchild=NULL;
		Btree->num=n;
		Btree->high=insert(n);
	}
	print(head);
	
	return 0;
}
int insert(int n){
	int cnt=1;
	int flag=0;
	Lnode p,q;
	p=head;
	while(p!=NULL){
		if(n<p->num){
			q=p;
			p=p->lchild;
			flag=0;
		}
		else{
			q=p;
			p=p->rchild;
			flag=1;
		}
		cnt++;
	}
	if(flag==0){
		q->lchild=Btree;
	}
	else if(flag==1){
		q->rchild=Btree;
	}
	return cnt;
}

void print(Lnode Btree){
	if(Btree->lchild!=NULL)
		print(Btree->lchild);
	if(Btree->rchild!=NULL)
		print(Btree->rchild);
	if(Btree->lchild==NULL&&Btree->rchild==NULL)
		printf("%d %d\n",Btree->num,Btree->high);
	return;
}

