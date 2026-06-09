#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
struct  node {
    int data;
    int depth;
    struct node *left, *right;
};
typedef struct node  BTNode;
typedef struct node  *BTNodeptr;
void  perorder(BTNodeptr t)
{
    if(t!=NULL){
     if(t->left==t->right&&t->right==NULL) 
	 printf("%d %d\n",t->data,t->depth);    
     perorder(t->left);
     perorder(t->right);
       }
}
void insert(BTNodeptr *root,int n,int deep)
{
	if(*root==NULL){
	*root=(BTNodeptr)malloc(sizeof(BTNodeptr));
	(*root)->data=n;
	(*root)->left=(*root)->right=NULL;
	(*root)->depth=deep;
	}
	else{
		if(n<(*root)->data)
		insert(&(*root)->left,n,deep+1);
		else 
		insert(&(*root)->right,n,deep+1);
    }
}
int main(){
	int num;
	BTNodeptr root=NULL;
	scanf("%d",&num);
	int i,n;
	for(i=0;i<num;i++){
		scanf("%d",&n);
		insert(&root,n,1);
	}
	perorder(root);
	return 0;
}

