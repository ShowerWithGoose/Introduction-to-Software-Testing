#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
struct node{
	int data;
	int depth;
	struct node *left;
	struct node *right;
};
typedef struct node *BTNodeptr;
typedef struct node BTNode;
BTNodeptr root=NULL;
void insert(int t){
	BTNodeptr p,q=root;
	p=(BTNodeptr)malloc(sizeof(BTNode));
	p->data=t;
	p->left=NULL;
	p->right=NULL;
	int count=1;
	if(root==NULL){
		p->depth=count;
		root=p;
	}
	else{
		while(1){
			count++;
			if(t<q->data){
				if(q->left==NULL){
					p->depth=count;
					q->left=p;
					break;
				}
				else q=q->left;
			}
			else if(t>=q->data){
				if(q->right==NULL){
					p->depth=count;
					q->right=p;
					break;
				}
				else q=q->right;
			}
		}
	}
}
void print(BTNodeptr p){
	if(p->left==NULL&&p->right==NULL){
		printf("%d %d\n",p->data,p->depth);
		return ;
	}
	else if(p->right==NULL) print(p->left);
	else if(p->left==NULL) print(p->right);
	else{
		print(p->left);
		print(p->right);
	}
}
int main(){
	int n,i,t;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&t);
		insert(t);
	} 
	print(root);
	return 0;
}


