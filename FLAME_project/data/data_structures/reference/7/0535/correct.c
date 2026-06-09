#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int keep;
	int depth;
	struct node *left;
	struct node *right;
}tree,*treep;
treep root=NULL;
int N,i,temp,depth=1;
void ins(treep*t,int temp,int depth);
void give_out(treep t);
int main(){
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&temp);
		ins(&root,temp,1);
	}
	give_out(root);
	return 0;
}
void ins(treep *t,int temp,int depth){
	if(*t==NULL){
		*t=(treep)malloc(sizeof(treep));
		(*t)->left=(*t)->right=NULL;
		(*t)->keep=temp;
		(*t)->depth=depth;
	}
	else if(temp<(*t)->keep){
		ins(&((*t)->left),temp,depth+1);
	}
	else{
		ins(&((*t)->right),temp,depth+1);
	}
}
void give_out(treep t){
		if(t!=NULL){
			if(t->left==NULL&&t->right==NULL)
			printf("%d %d\n",t->keep,t->depth);
			
			give_out(t->left);
		    give_out(t->right);
		}
		
	}

