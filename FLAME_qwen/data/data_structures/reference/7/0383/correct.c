#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	int d;
	struct node *lchild;
	struct node *rchild;
}node;
node *head;
void visit(node *p){
	if(p->lchild==NULL&&p->rchild==NULL){
		printf("%d %d\n",p->data,p->d);
	}
}
void traverse(node *p){
	if(p != NULL){
		visit(p);
		traverse(p->lchild);
		traverse(p->rchild);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int data;
		scanf("%d",&data);
		if(head == NULL){
			head = (node *)malloc(sizeof(node));
			head->data = data;
			head->d = 1;
			head->lchild = NULL;
			head->rchild = NULL;
			continue;
		}
		node *p = head;
		while(1){
			if(data<p->data){
				if(p->lchild == NULL){
					node *tmp = (node *)malloc(sizeof(node));
					tmp->data = data;
					tmp->d = p->d+1;
					p->lchild = tmp;
					tmp->lchild = NULL;
					tmp->rchild = NULL;
					break;
				}
				else{
					p = p->lchild;
				}		
			}
			else{
				if(p->rchild == NULL){
					node *tmp = (node *)malloc(sizeof(node));
					tmp->data = data;
					tmp->d = p->d+1;
					p->rchild = tmp;
					tmp->lchild = NULL;
					tmp->rchild = NULL;
					break;
				}
				else{
					p = p->rchild;
				}
			}
		}
	}
	traverse(head);
	return 0;
}

