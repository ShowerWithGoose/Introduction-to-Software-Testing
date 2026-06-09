#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
	int num;
    struct tree *left,*right;
}node;
typedef struct tree *nodeptr;
nodeptr root=NULL;

void buildtree(int data){
	nodeptr p,q,t;
	p=(nodeptr)malloc(sizeof(node));
	p->num=data;
	p->left=p->right=NULL;
	if(root==NULL){
		root=p;
		return;
	}
	else{
		q=(nodeptr)malloc(sizeof(node));
		q=root;
		while(q!=NULL){
			if(data<q->num){
				t=q;
				q=q->left;
			}
			else{
				t=q;
				q=q->right;
			}
		}
		if(data<t->num)
		  t->left=p;
		else
		  t->right=p;
	}
	return;
}

void search(nodeptr r,int h){
	if(r->left!=NULL)
	  search(r->left,h+1);
	if(r->right!=NULL)
	  search(r->right,h+1);
	if(r->left==NULL &&r->right==NULL)
	  printf("%d %d\n",r->num,h);
}

int main(){
	int n,data;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		buildtree(data);
	}
	search(root,1);
	return 0;
}

