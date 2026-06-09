#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct tree{
	int data;
	struct tree *left;
	struct tree *right;
	struct tree *before;
	int height;
}Tree;

int Insert(Tree* Root,int item){
	int height=1;
	//if Root==NULL
	Tree *p=Root,*q;
	q=(Tree*)malloc(sizeof(Tree));
	q->data=item; 
	q->left=NULL;
	q->right=NULL;
	
	while(1){
		height++;
		if(item<p->data) {
			if(p->left==NULL) {
				q->height=height;
				q->before=p;
				p->left=q;
				break;
			}
			else p=p->left;
		}
		else if(item>=p->data) {
			if(p->right==NULL) {
				q->height=height;
				q->before=p;
				p->right=q;
				break;
			}
			else p=p->right;
		}
	}
	
}


int DeepTree(Tree *Root){
	int leftdeep=0,rightdeep=0;
	if(Root==0) return 0;
	else {
		leftdeep=DeepTree(Root->left);
		rightdeep=DeepTree(Root->right);
		if(leftdeep>rightdeep) 
			return leftdeep+1;
		else  
			return rightdeep+1;
	}
}

int Visit(Tree* t){
	if(t==NULL) return 0;
	else if(t->left==NULL&&t->right==NULL)
	 	printf("%d %d\n", t->data, t->height);
	return 0;
}

void inorder(Tree* t){
	if(t!=NULL){
		inorder(t->left);
		Visit(t);
		inorder(t->right);
	}
}

int main(){
	Tree *Root=NULL,*p,*r,*l;
	int n,i=0,item=0;
	scanf("%d",&n);
	
	Root=(Tree *)malloc(sizeof(Tree));
	scanf("%d",&Root->data);//
	Root->left=NULL;
	Root->right=NULL;
	Root->height=1;
	
	for(i=0;i<n-1;i++){
		scanf("%d",&item);
		Insert(Root,item);
	}	
	
	inorder(Root);
	return 0;
	
}
 

