#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	int high;
	struct node *lchild,*rchild;
};
typedef struct node TBTNode;
typedef struct node *TBTNodeptr;
int h;
TBTNodeptr root=NULL;
TBTNodeptr insertBST(TBTNodeptr p,int item);
void out(TBTNodeptr p);
int main()
{
	int n;
	int item;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&item);
		h=0;
		root=insertBST(root,item);
	}
	out(root);
	return 0;
}
TBTNodeptr insertBST(TBTNodeptr p,int item){
	h++;
	if(p==NULL){
		p=(TBTNodeptr)malloc(sizeof(TBTNode));
		p->data=item;
		p->high=h;
		p->lchild=p->rchild=NULL;
	}
	else if(item<p->data){
		p->lchild=insertBST(p->lchild,item);
	}
	else if(item>=p->data){
		p->rchild=insertBST(p->rchild,item);
	}
	return p;
}
void out(TBTNodeptr p){
	if(p!=NULL){
		if(p->lchild==NULL&&p->rchild==NULL){
			printf("%d %d\n",p->data,p->high);
		}
			out(p->lchild);	
			out(p->rchild);	
	}
}

