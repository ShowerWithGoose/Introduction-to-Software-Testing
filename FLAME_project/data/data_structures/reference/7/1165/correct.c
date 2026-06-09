#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct node{
	int data;
	int stack;
	struct node *lchild,*rchild;
}*root;
typedef struct node Node,*Nodeptr;
Nodeptr insert(Nodeptr p,int item,int count);
void dfstree(Nodeptr t);
int main(){
	int n,mid;
	scanf("%d",&n);
	root=(Nodeptr)malloc(sizeof(Nodeptr));
	root=NULL;
	for(int i=1;i<=n;i++){
		scanf("%d",&mid);	
		root=insert(root,mid,0);	
	}
	dfstree(root);
	return 0;
}
Nodeptr insert(Nodeptr p,int item,int count){
	count++;
	if(p==NULL){
		p=(Nodeptr)malloc(sizeof(Nodeptr));
		p->data=item;
		p->stack=count;
		p->lchild=NULL;
		p->rchild=NULL;
	}
	else if(item<p->data)
		p->lchild=insert(p->lchild,item,count);
	else if(item>=p->data)
		p->rchild=insert(p->rchild,item,count);
	count--;
	return p;
}
void dfstree(Nodeptr t){
	if(t!=NULL){
		if(t->lchild==NULL&&t->rchild==NULL){
			printf("%d %d\n",t->data,t->stack);
		}
		dfstree(t->lchild);			
		dfstree(t->rchild);			
	}
}

