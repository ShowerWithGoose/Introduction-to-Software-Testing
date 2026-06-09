#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
typedef struct TreeNode {
    int num;
    struct TreeNode *left;
    struct TreeNode *right;
    int d;
}Tree,*Treep;
Treep root=NULL;
void lsort(Treep t){
    if(t!=NULL){
        lsort(t->left);
        if(t->left==NULL && t->right==NULL)
            printf("%d %d\n",t->num,t->d);
        lsort(t->right);
    }
}
void BST(Treep *t,int nums,int d){
	if(*t==NULL){
		*t=(Treep)malloc(sizeof(Treep));
		(*t)->left=(*t)->right=NULL;
		(*t)->num=nums;
		(*t)->d=d;
	}
	else if(nums<(*t)->num){
		BST(&((*t)->left),nums,d+1);
	}
	else{
		BST(&((*t)->right),nums,d+1);
	}
}
int main(){
    int i,m,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		BST(&root,m,1);
	}
	lsort(root);
	return 0;
}

