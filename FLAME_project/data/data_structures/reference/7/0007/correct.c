#include<stdio.h> 
#include<math.h>
#include<stdlib.h> 
#include<string.h> 
#include<stdbool.h> 
#include<ctype.h>
struct TreeNode{
	int num;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
	int depth;
};
typedef struct TreeNode Tree;
typedef struct TreeNode* Treep;
void outTree(Treep p);
void insertBST(Treep *p,int value,int depth);
Treep root=NULL;
int n,x;
int main(){ 
scanf("%d",&n);
int i;
for(i=0;i<n;i++){
	scanf("%d",&x);
	insertBST(&root,x,1);
}
outTree(root);
 
return 0;
}
void insertBST(Treep *p,int value,int depth){
	if(*p==NULL){
		*p=(Treep)malloc(sizeof(Treep));
		(*p)->lchild=(*p)->rchild=NULL;
		(*p)->num=value;
		(*p)->depth=depth;
		
	}else if(value<(*p)->num){
		insertBST(&((*p)->lchild),value,depth+1);
	}else{
		insertBST(&((*p)->rchild),value,depth+1);
	}
}
void outTree(Treep p){
	if(p!=NULL){
		outTree(p->lchild);
		if(p->lchild==NULL&&p->rchild==NULL) printf("%d %d\n",p->num,p->depth);
		outTree(p->rchild);		
	}
}

