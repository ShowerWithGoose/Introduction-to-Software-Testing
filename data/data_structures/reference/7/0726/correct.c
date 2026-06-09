#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct node{
	int num;
	int l;
	struct node *left,*right;
};
typedef struct node Node;
Node *root=NULL;
void in(int a){
	Node *p,*q;
	p=(Node *)malloc(sizeof(Node));
	memset(p,0,sizeof(Node));
	p->num=a;
	p->l=1;
	if(root==NULL) root=p;
	else{
		q=root;
		while(1){
			p->l++;
			if(a<q->num){
				if(q->left==NULL){
					q->left=p;
					break;
				}
				else q=q->left;
			}
			else{
				if(q->right==NULL){
					q->right=p;
					break;
				}
				else q=q->right;
			}
		}
	}
}
void pre(Node *p){
	if(p->left!=NULL) pre(p->left);
	if(p->right!=NULL) 	pre(p->right);
	if(p->left==NULL&&p->right==NULL) printf("%d %d\n",p->num,p->l);
}
int main(){
	int n,a;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		in(a);
	}
	pre(root);
	return 0;
}


