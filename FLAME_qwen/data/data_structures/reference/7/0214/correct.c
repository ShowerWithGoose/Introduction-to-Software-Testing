#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct bst_{
	int num;
	struct bst_ * left;
	struct bst_ * right;
} * pBst;
pBst Create_Tree(pBst root,int x){
	int i,j,k;
	pBst pNew;
	if(root==NULL){
		pNew=(pBst)malloc(sizeof(struct bst_));
		pNew->num =x;pNew->left =NULL;pNew->right =NULL; 
		return pNew;
	}
	if(root->left ==NULL&&root->right ==NULL){
		pNew=(pBst)malloc(sizeof(struct bst_));
		pNew->num =x;pNew->left =NULL;pNew->right =NULL; 
		if(root->num <=x) root->right =pNew; 
		else root->left =pNew;
	}
	else if(root->num <=x){
		root->right=Create_Tree(root->right ,x);
	}
	else {
		root->left =Create_Tree(root->left ,x);
	}
	return root;
}
void pr(pBst root,int height){
	int i,j,k;
	if(root->left !=NULL) pr(root->left ,height+1);
	if(root->left ==NULL&&root->right ==NULL){
		printf("%d %d\n",root->num ,height);return;
	}
	if(root->right !=NULL) pr(root->right ,height+1);
}

int main()
{
	int i,j,k;
	int n,x;
	scanf("%d",&n);
	pBst Root=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		Root=Create_Tree(Root,x);
	}
	pr(Root,1);
	return 0;
 } 

