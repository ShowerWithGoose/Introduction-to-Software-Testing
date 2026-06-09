#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct node{
	int a;
	int d;
	struct node *r,*l;
}node;
typedef struct tree{
	node *root;
}tree;
void Init(tree *s){
	s->root=NULL;
}
void insert(tree *s,int a){
	node *n=(node*)malloc(sizeof(node));
	n->a=a;
	n->l=NULL;
	n->r=NULL;
	if(s->root==NULL){
		n->d=1;
		s->root=n;	
	}
	else{
		int d=2;
		node *t=s->root;
		while(t!=NULL){
			if(a<t->a){
				if(t->l==NULL){
					n->d=d;
					t->l=n;
					return;
				}
				else{
					d++;
					t=t->l;
				}
			}
			else{
				if(t->r==NULL){
					n->d=d;
					t->r=n;
					return;
				}
				else{
					d++;
					t=t->r;
				}
			}
		}
	}	
}
void pre(node *n){
	if(n!=NULL){
		if(n->l==NULL&&n->r==NULL){
			printf("%d %d\n",n->a,n->d);
		}
		pre(n->l);
		pre(n->r);
	}
	else{
		return;
	}
}
int main(){
	tree s;
	Init(&s);
	int n,a;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a);
		insert(&s,a);
	}
	pre(s.root);
	return 0;
}



