#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int num;
	struct node *lchild,*rchild;
	int height;
}BITNode,*BITNodeptr;
BITNodeptr root=NULL;
void insertBIT(int );
void inorder(BITNodeptr);
int main(){
	int n;
	int data;
	int i=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&data);
		insertBIT(data );
	}
	inorder(root);
	
return 0;
} 

void insertBIT(int data){
	BITNodeptr t;
	BITNodeptr p;
	
	t=(BITNodeptr)malloc(sizeof(BITNode));
	t->num =data;
	t->lchild =t->rchild =NULL; 
	t->height =1;
	if(root==NULL){//二叉树为空的情况 
		root=t;
	}
	else{
		p=root;
		while(1){
			if(data<p->num ){
				if(p->lchild ==NULL){
					t->height ++;
					p->lchild =t;
					break;
				}
				else{
					t->height ++;
					p=p->lchild ;
				}
			}
			else if(data>=p->num ){
				if(p->rchild ==NULL){
					t->height ++;
					p->rchild =t;
					break;
				}
				else{
					t->height ++;
					p=p->rchild ;
				}
			}
		}
	}
}

void inorder(BITNodeptr p){
	if(p!=NULL){
		inorder(p->lchild );
		if(p->lchild ==NULL&&p->rchild ==NULL){
			printf("%d %d\n",p->num ,p->height );
		}
		inorder(p->rchild );
	}
}

