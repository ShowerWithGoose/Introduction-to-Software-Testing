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
	int n,i,j;
	scanf("%d",&n);
	
	treeptr head=(treeptr)malloc(sizeof(struct Node));
	head->lchild=NULL;
	head->rchild=NULL; 
	treeptr q=head;
	scanf("%d",&head->data);
	head->height=1;
	for(i=0;i<n-1;i++,q=head){
		treeptr p=(treeptr)malloc(sizeof(struct Node));
		p->lchild=NULL;
		p->rchild=NULL; 
		scanf("%d",&p->data);
		int level=1;
		while(1){
			if(q->data>p->data){
				if(q->lchild==NULL){
					q->lchild=p;
					p->height=q->height+1;
					break;
				}else{
					q=q->lchild;
				}
			}else{
				if(q->rchild==NULL){
					q->rchild=p;
					p->height=q->height+1;
					break;
				}else{
					q=q->rchild;
				}
			}
		}
	}
	preorder(q);
	return 0;
}

