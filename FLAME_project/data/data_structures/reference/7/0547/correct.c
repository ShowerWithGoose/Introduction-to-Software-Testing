#include<stdio.h>
#include<stdlib.h>
struct node {
	int val;
	int hei;
	struct node *left,*right;
};
typedef struct node btnode;
typedef struct node *btnodeptr;
btnodeptr insertbst(btnodeptr p,int x,int h) {
	if(p==NULL) {
		p=(btnodeptr)malloc(sizeof(btnode));
		p->val=x;
		p->hei=h;
		p->left=p->right=NULL;
	} else if(x<p->val) p->left=insertbst(p->left,x,h+1);
	else if(x>=p->val) p->right=insertbst(p->right,x,h+1);
	return p;
}
void outputbst(btnodeptr t) {
	btnodeptr stack[1005],p=t;
	int top=-1;
	if(t!=NULL) {
		do {
			while(p!=NULL) {
				stack[++top]=p;
				p=p->left;
			}
			p=stack[top--];
			if((p->left==NULL)&&(p->right==NULL)) printf("%d %d\n",p->val,p->hei);
			p=p->right;
		}while(!(p==NULL&&top==-1));
	}
}

int main() {
	int n,i,x;
	scanf("%d",&n);
	btnodeptr root=NULL;
	for(i=0; i<n; i++) {
		scanf("%d",&x);
		root=insertbst(root,x,1);
	}
	outputbst(root);
	return 0;
}



