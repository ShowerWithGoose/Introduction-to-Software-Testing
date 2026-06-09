#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
typedef struct Node{
	int data;
	int depth;
	struct Node* llink;
	struct Node* rlink;
}BTree,*TREE; 
TREE insert(TREE p,int newdata,int deep);
void inorder(TREE p);
int main(){
	int sum;
	scanf("%d",&sum);
	TREE root=NULL;
	for(int i=0;i<sum;i++){
		int newdata=0;
		scanf("%d",&newdata);
		root=insert(root,newdata,1);
	}
	inorder(root);
	return 0;
}
TREE insert(TREE p,int newdata,int deep){
	if(p==NULL){
		p=malloc(sizeof(BTree));
		p->depth=deep;
		p->data=newdata;
		p->llink=NULL;
		p->rlink=NULL;
	}
	else if(p!=NULL){
		if(newdata<(p->data)){
		   p->llink=insert(p->llink,newdata,deep+1);
		}
		else  if(newdata>=(p->data)){
		   p->rlink=insert(p->rlink,newdata,deep+1);

		}
	}
	return p;
}
void inorder(TREE p){
	if(p!=NULL){
	    if(p->llink==NULL&&p->rlink==NULL)
		{
		printf("%d %d\n",p->data,p->depth);
	    }
	    inorder(p->llink);
	    inorder(p->rlink);
	    
	}
}

