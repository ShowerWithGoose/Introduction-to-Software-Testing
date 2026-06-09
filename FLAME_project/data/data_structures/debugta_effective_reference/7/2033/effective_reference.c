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
void insert(BTNodeptr *root,int num,int h)
{
	if(*root==NULL){
	*root=(BTNodeptr)malloc(sizeof(BTNodeptr));
	(*root)->data=num;
	(*root)->left=(*root)->right=NULL;
	(*root)->depth=h;
	}
	else{
		if(num<(*root)->data)
		insert(&(*root)->left,num,h+1);
		else 
		insert(&(*root)->right,num,h+1);
    }
}
int main(){
	int n;
	BTNodeptr root=NULL;
	scanf("%d",&n);
	int i,num;
	for(i=0;i<n;i++){
		scanf("%d",&num);
		insert(&root,num,1);
	}
	perorder(root);
	return 0;
}

