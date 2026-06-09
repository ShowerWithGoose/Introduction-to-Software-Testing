#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define M 1024

struct node{
	int data;
	struct node *lchild,*rchild;
};
typedef struct node BTNode,*BTNodeptr;
BTNodeptr root;
BTNodeptr insertBST(BTNodeptr p,int item)
{
	if(p==NULL){
		p=(BTNodeptr)malloc(sizeof(BTNode));
		p->data=item;
		p->lchild=p->rchild=NULL;
	}
	else if(item<p->data)
	    p->lchild=insertBST(p->lchild,item);
	else if(item>=p->data)
	    p->rchild=insertBST(p->rchild,item);
	return p;
}
void inorder(BTNodeptr p)
{
	BTNodeptr STACK[M],t=p;
	int top=-1;
	if(p!=NULL)
	  do{
	  	while(t!=NULL){
	  		STACK[++top]=t;
	  		t=t->lchild;
		  }
		t=STACK[top--];
		VISIT(t);
		t=t->rchild;
	  }while(!(t==NULL&&top==-1));
	  else{
	  	VISIT(p);
	  }
}
void VISIT(BTNodeptr p)
{
	if(p!=NULL&&p->lchild==NULL&&p->rchild==NULL)
	printf("%d %d\n",p->data,depth(p));
	return;
}
int depth(BTNodeptr p)
{
	BTNodeptr t=root;
	int i=1;
	while(t!=NULL){
		if(t->data==p->data&&t->lchild==NULL&&t->rchild==NULL)
		return i;
		else if(t->data>p->data){
			t=t->lchild;
			i++;
		}else{
			t=t->rchild;
			i++;
		}
	}
}
int main()
{
	int i,item,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&item);
		root=insertBST(root,item);
	}
	inorder(root);
	return 0;
}

