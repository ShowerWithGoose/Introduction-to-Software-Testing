#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *lc,*rc;
};
typedef struct node tree,*treest;
treest insert(treest p,int item){
	if(p==NULL){
		p=(treest)malloc(sizeof(tree));
		p->data=item;
		p->lc=p->rc=NULL;
	}
	else
	if(p->data<=item){
		p->rc=insert(p->rc,item);
	}
	else
	if(p->data>item){
		p->lc=insert(p->lc,item);
	}
	return p;
}
treest ask(treest p,int t){
	if(p->lc==NULL&&p->rc==NULL){
		printf("%d %d\n",p->data,t);
		return;
	}
	if(p->lc!=NULL) 
	ask(p->lc,t+1);
	if(p->rc!=NULL)
	ask(p->rc,t+1);
	return;
}
int main(){
	int n,v;
	scanf("%d",&n);
	treest root;
	root=NULL;
	while(n--){
		scanf("%d",&v);
		root=insert(root,v);
	}
	ask(root,1);
	return 0;
}

