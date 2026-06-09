#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
	int num;
	int height;
	struct node *left,*right;
};
typedef struct node BSTNode;
typedef struct node *BSTNodeptr;
BSTNodeptr root=NULL;
BSTNodeptr insertBST(BSTNodeptr p,int x,int len);
BSTNodeptr searchBST(BSTNodeptr t,int x);
void inorder(BSTNodeptr t);
int max(int x,int y);
int heightTree(BSTNodeptr p);
int main()
{
	int i,n,m;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		int len=0;
		root=insertBST(root,m,len);
	}
	inorder(root);
	return 0;
}
BSTNodeptr insertBST(BSTNodeptr p,int x,int len){
	len++;
	if(p==NULL){
		p=(BSTNodeptr)malloc(sizeof(BSTNode));
		p->num=x;
		p->left=p->right=NULL;
		p->height=len;
	}
	else if(x<p->num){
		p->left=insertBST(p->left,x,len);
	}
	else if(x>=p->num){
		p->right=insertBST(p->right,x,len);
	}
	return p;
}
BSTNodeptr searchBST(BSTNodeptr t,int x){
	BSTNodeptr p=t;
	while(p!=NULL){
		if(x==p->num)
			return p;
		if(x>p->num)
			p=p->right;
		else
			p=p->left;
	}
	return NULL;
}
void inorder(BSTNodeptr t){
	if(t!=NULL){
		
		inorder(t->left);
		if(t->left==NULL&&t->right==NULL)
			printf("%d %d\n",t->num,t->height);
		inorder(t->right);
	}
}
int max(int x,int y){
	if(x>y)	return x;
	else	return y;
}
int heightTree(BSTNodeptr p){
	if(p==NULL)	return 0;
	else	return 1+max(heightTree(p->left),heightTree(p->right));
}

