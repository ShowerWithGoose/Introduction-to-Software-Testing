#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
struct node{
	int data;
	struct node *lchild,*rchild;
};
typedef struct node *Nodeptr;
typedef struct node Node;
Nodeptr list=NULL;
Nodeptr insert(Nodeptr p,int a){
	if(p==NULL){
		p=(Nodeptr)malloc(sizeof(Nodeptr));
		p->data=a;
		p->lchild=p->rchild=NULL;
	}else if(a<p->data){
		p->lchild=insert(p->lchild,a);
	}else{
		p->rchild=insert(p->rchild,a);
	}
	return p;
}
void pprint(Nodeptr q,int i){
	if(q->lchild!=NULL){
		pprint(q->lchild,i+1);
	}
	if(q->rchild!=NULL){
		pprint(q->rchild,i+1);
	}
	if(q->lchild==NULL&&q->rchild==NULL){
		printf("%d %d\n",q->data,i);
	}	
}
int main(){
	int a,n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		list=insert(list,a);
	}
	pprint(list,1);
	return 0;
}
