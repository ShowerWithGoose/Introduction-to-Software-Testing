#include <stdio.h>
#include <math.h>
#include <string.h>
#define eps 1e-10
#define NULL ((void *)0)
#include <ctype.h>
#include <stdlib.h>
#define M 1024
typedef struct node{
	int data;
	int id;
	struct node *lchild ,*rchild;
}Node,*PNode;

PNode root = NULL;
int h[M];
int num = 1;

void insert(int item){
	PNode p,q;
	int height = 1;
	p = (PNode)malloc(sizeof(Node));
	p->data = item;
	p->id = num;
	p->lchild = NULL;
	p->rchild = NULL;
	num++;
	
	if(root == NULL) root = p;
	else {
		q = root;
		while(1){
			height++;
			if(item < q->data){
				if(q->lchild == NULL){
					q->lchild = p;
					break;
				}
				else q = q->lchild;
			}
			else if(item >= q->data){
				if(q->rchild == NULL){
					q->rchild = p;
					break;
				}
				else q= q->rchild;
			}
			else break;
		}
	}
	h[p->id] = height;
}
void inorder(PNode t){
	PNode stack[M],p = t;
	int top = -1;
	int height;
	if(t != NULL){
		do{
			for(;p != NULL;p = p->lchild) stack[++top] = p;
			p = stack[top--];
			if(p->lchild == NULL && p->rchild == NULL){
				height = h[p->id];
				printf("%d %d\n",p->data,height);
			}
			p = p->rchild;
		}while(p != NULL || top != -1);
	}
}
int main(){
	int n,a;
	scanf("%d",&n); 
	int i;
	for(i = 0;i < n;i++){
		scanf("%d",&a);
		insert(a);
	}
	inorder(root);


return 0;
}


