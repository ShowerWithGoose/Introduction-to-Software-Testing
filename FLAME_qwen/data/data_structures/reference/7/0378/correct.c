#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	struct node *l,*r;
	int val,d;
}treenode;
treenode *tree=NULL;
void insert(int v){
	treenode *tmp=(treenode*)malloc(sizeof(treenode));
	treenode *t=tree;
	tmp->l=NULL;
	tmp->r=NULL;
	tmp->val=v;
	tmp->d=1;
	if(tree==NULL){
		tree=tmp;
		return;
	}
	while(1){
		if(v<t->val){
			tmp->d++;
			if(!t->l){
				t->l=tmp;
				break;
			}else{
				t=t->l;
			}
		}else if(v>=t->val){
			tmp->d++;
			if(!t->r){
				t->r=tmp;
				break;
			}else{
				t=t->r;				
			}	
		}
	}
	return;
}
void traversal(treenode *t){
	if(!t->l&&!t->r)	printf("%d %d\n",t->val,t->d);
	else{
		if(t->l)	traversal(t->l);
		if(t->r)	traversal(t->r);
	}
}

int main()
{
	int n,v;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&v);
		insert(v);
	}
	traversal(tree);
	return 0;
} 

