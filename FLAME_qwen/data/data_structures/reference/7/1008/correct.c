#include<stdio.h>
#include<stdlib.h>
struct node{
	int data, h;
	struct node *left, *right;
};
typedef struct node BTNode;
typedef struct node *BTNodeptr;
BTNodeptr p;
BTNodeptr Root = NULL; //Root是一个全局变量
void insertBST(int item){
	int h0 = 1;
    BTNodeptr p, q;
    p=(BTNodeptr)malloc(sizeof(BTNode));
    p->data=item;
    p->left=NULL;
    p->right=NULL;
    if(Root == NULL){
    	Root = p;
    	Root->h = h0;
	}
	else{
		q = Root;
		while(1){
			if(item < q->data){
				if(q->left == NULL){
					p->h = h0+1;
					q->left = p;
					break;
				}
				else{
					q = q->left;
					h0++;
				}
			}
			else{
				if(q->right == NULL){
					p->h = h0+1;
					q->right = p;
					break;
				}
				else{
					q = q->right;
					h0++;
				}
			}
		}
	}		
}
void preorder(BTNodeptr p){
	if(p != NULL){
		if(p->left == NULL && p->right == NULL)
			printf("%d %d\n",p->data, p->h);
		preorder(p->left);
		preorder(p->right);
	}	
}
void  destroyTree(BTNodeptr p){
    if(p != NULL){
         destroyTree(p->left);
         destroyTree(p->right);
         free(p);
    }
}
int main(){
	int N, i, num;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d", &num);
		insertBST(num);
	}
	preorder(Root);
	destroyTree(Root);
}

