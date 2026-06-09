#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct Node{
	int data;
	int height;
	struct Node *lchild,*rchild;
};
typedef struct Node tree;
typedef struct Node *treeptr;
void preorder(treeptr t){
	if(t!=NULL){
//		printf("%d\n",t->data);
		if(t->rchild==NULL&&t->lchild==NULL){
			printf("%d %d\n",t->data,t->height);
		}
		preorder(t->lchild);
		preorder(t->rchild);
		
	}
	return ;
}

int main(){
	int num,i,j;
	scanf("%d",&num);
	
	treeptr head=(treeptr)malloc(sizeof(struct Node));
	head->lchild=NULL;
	head->rchild=NULL; 
	treeptr p=head;
	scanf("%d",&head->data);
	head->height=1;
	for(i=0;i<num-1;i++,p=head){
		treeptr q=(treeptr)malloc(sizeof(struct Node));
		q->lchild=NULL;
		q->rchild=NULL; 
		scanf("%d",&q->data);
		int line=1;
		while(1){
			if(p->data>q->data){
				if(p->lchild==NULL){
					p->lchild=q;
					q->height=p->height+1;
					break;
				}else{
					p=p->lchild;
				}
			}else{
				if(p->rchild==NULL){
					p->rchild=q;
					q->height=p->height+1;
					break;
				}else{
					p=p->rchild;
				}
			}
		}
	}
	preorder(p);
	return 0;
}

