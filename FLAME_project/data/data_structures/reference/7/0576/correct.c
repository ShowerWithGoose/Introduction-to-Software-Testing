#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
	int data;
	int high;
	struct node* left,*right;
}*p=NULL,*q=NULL,*root=NULL;

void insert(int item);
void preorder(struct node* t);
int visit(struct node* t);

int main (){
	int n,i,item;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&item);
		insert(item);
	}
	preorder(root);
}

void insert(int item){
	int i=1;
	p=(struct node*)malloc(sizeof(struct node));
	p->data =item;
	p->left =NULL;
	p->right =NULL;
	if(root==NULL){
		p->high =1;
		root=p;
	}
	else{
		q=root;
		while(1){
			if(q->data >item){
				if(q->left ==NULL){
					p->high =++i;
					q->left =p;
					break;
				}
				else q=q->left ;
			}	
			else if(q->data <=item){
				if(q->right ==NULL){
					p->high =++i;
					q->right =p;
					break;
				}
				else q=q->right ;
			}	
			i++;
		}
	}
}

void preorder(struct node* t){
	if(t!=NULL){
		visit(t);
		preorder(t->left );
		preorder(t->right );
	}
}

int visit(struct node* t){
	if(t->left ==NULL&&t->right ==NULL){
		printf("%d %d\n",t->data ,t->high );
	}
}
