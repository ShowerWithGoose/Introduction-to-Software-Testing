#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

typedef struct l{
	int key;
	struct l *par;
	struct l *lc;
	struct l *rc;
} tree;
tree root;
void INTREE(tree*,tree*);
void FOUND(tree*,int);
int main()
{
	int n,i,t;
	tree *p;
	scanf("%d",&n);
	scanf("%d",&t);
	root.key = t;
	for(i=1;i<n;i++){
		scanf("%d",&t);
		p = (tree*)malloc(sizeof(tree));
		p->lc = p->rc = p->par = NULL;//没初始化还真是不行 
		p->key = t;
		INTREE(&root,p);
	}
	FOUND(&root,1);
	return 0;
}

void FOUND(tree*t,int dep)
{
	if(t->lc==NULL&&t->rc==NULL){
		printf("%d %d\n",t->key,dep);
		return;
	}
	if(t->lc!=NULL){
		FOUND(t->lc,dep+1);
	}
	if(t->rc!=NULL){
		FOUND(t->rc,dep+1);
	}
	return;
}
void INTREE(tree*t,tree*p)
{
	if(p->key>=t->key){
		if(t->rc==NULL){
			t->rc = p;
			p->par = t;
			return;
		}
		else{
			INTREE(t->rc,p);
		}
	}
	else if(p->key<t->key){
		if(t->lc==NULL){
			t->lc = p;
			p->par = t;
			return;
		}
		else{
			INTREE(t->lc,p);
		}
	}
	return;
}
















