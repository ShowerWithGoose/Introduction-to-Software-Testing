#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node* lchild;
	struct node* rchild;
	int h;
} Node,*nodeptr;
nodeptr insert(nodeptr p,int num,int height) {
	if(p==NULL) {
		p=(nodeptr)malloc(sizeof(Node));
		p->data=num;
		p->lchild=p->rchild=NULL;
		p->h=height;
	} else if(num<p->data)
		p->lchild=insert(p->lchild,num,++height);
	else if(num>=p->data)
		p->rchild=insert(p->rchild,num,++height);
	return p;
}
void inorder(nodeptr t) {
	nodeptr stack[1000],p=t;
	int top=-1;
	if(t!=NULL) {
		do {
			while(p!=NULL) {
				stack[++top]=p;
				p=p->lchild;
			}
			p=stack[top--];
			if(p->lchild==NULL&&p->rchild==NULL)
				printf("%d %d\n",p->data,p->h);
			p=p->rchild;
		} while(!(p==NULL&&top==-1));
	}
}
int main() {
	int sum,num;
	scanf("%d",&sum);
	nodeptr tree=NULL;
	for(int i=1; i<=sum; i++) {
		scanf("%d",&num);
		tree=insert(tree,num,1);
	}
	inorder(tree);
	return 0;
}

