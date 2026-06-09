#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct leave{
	int number;
	int generation;
	struct leave *left, *right;
};
typedef struct leave BTNode;
typedef struct leave *BTNodeptr;
BTNodeptr root=NULL;
void insert(int a);
void output(BTNodeptr node);
int main(){
	int n, a[500], i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		insert(a[i]);
	}
	output(root);
	return 0;
}
void insert(int a){
	BTNodeptr p, q;
	p=(BTNodeptr)malloc(sizeof(BTNode));
	p->number=a;
	p->left=NULL;
	p->right=NULL;
	if(root==NULL){
		root=p;
		root->generation=1;
	}
	else{
		q=root;
		while(1){
			if(p->number<q->number){
				if(q->left==NULL){
					q->left=p;
					p->generation=q->generation+1;
					break;
				}
				else{
					q=q->left;
				}
			}
			else if(p->number>=q->number){
				if(q->right==NULL){
					q->right=p;
					p->generation=q->generation+1;
					break;
				}
				else{
					q=q->right;
				}
			}
		}
	}
}
void output(BTNodeptr node){
	if(node!= NULL){
		if(node->left==NULL && node->right==NULL){
			printf("%d %d\n",node->number,node->generation);
		}
		output(node->left);
		output(node->right);
	}
}


