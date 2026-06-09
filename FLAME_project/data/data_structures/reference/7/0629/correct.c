#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int curdepth=1;
struct tree {
	int data;
	int depth;
	struct tree *lkid;
	struct tree *rkid;
};
typedef struct tree *Btree;
typedef struct tree Bnode;
void insert(Btree *t,int a) {
	
	if(*t==NULL) {
		*t=(Btree)malloc(sizeof(Bnode));
	(*t)->data=a;
	(*t)->lkid=NULL;
	(*t)->rkid=NULL;
	(*t)->depth=curdepth;
	} else if(a<(*t)->data)
		insert(&((*t)->lkid),a);
	else
		insert(&((*t)->rkid),a);
		
	return;
}
Btree sorttree(int n) {
	Btree t=NULL;
int k;
int i;
	if(n>0)
		for( i=0; i<n; i++) {
			scanf("%d",&k);
			insert(&t,k);
		}
	return t;
}
void print(Btree s,int m) {
	if(s!=NULL) {
		if(s->lkid==NULL&&s->rkid==NULL)
		printf("%d %d\n",s->data,m);
		print(s->lkid,m+1);
		print(s->rkid,m+1);
	}
	return;
}
int main() {
	int n;
	scanf("%d",&n);
	Btree p=sorttree(n);
	print(p,1);
	return 0;
}

