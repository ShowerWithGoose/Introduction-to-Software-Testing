#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct leave{
	int number;
	int height;
	struct leave *left, *right;
};
typedef struct leave BTNode;
typedef struct leave *BTNodeptr;
BTNodeptr root=NULL;
void insert(int m);
void output(BTNodeptr node);
int main(){
	int n, m[500], i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m[i]);
		insert(m[i]);
	}
	output(root);
	return 0;
}
void insert(int m){
	BTNodeptr p, now;
	p=(BTNodeptr)malloc(sizeof(BTNode));
	p->number=m;
	p->left=NULL;
	p->right=NULL;
	if(root==NULL){
		root=p;
		root->height=1;
	}
	else{
		now=root;
		while(1){
			if(p->number<now->number){
				if(now->left==NULL){
					now->left=p;
					p->height=now->height+1;
					break;
				}
				else{
					now=now->left;
				}
			}
			else if(p->number>=now->number){
				if(now->right==NULL){
					now->right=p;
					p->height=now->height+1;
					break;
				}
				else{
					now=now->right;
				}
			}
		}
	}
}
void output(BTNodeptr node){
	if(node!= NULL){
		if(node->left==NULL && node->right==NULL){
			printf("%d %d\n",node->number,node->height);
		}
		output(node->left);
		output(node->right);
	}
}


