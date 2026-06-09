#include<stdio.h>
int num[1000],i,n,cnt=0;
typedef struct node {
	int deep;
	int data;
	struct node *lchild;
	struct node *rchild;
} Node;
Node* tree[1000];
void preorder(Node* root) {
	if(root->lchild==NULL && root->rchild==NULL) {
		printf("%d %d\n", root->data, root->deep);
		return;
	}
	if(root->lchild!=NULL) preorder(root->lchild);
	if(root->rchild!=NULL) preorder(root->rchild);
	return;
}
int main() {
	Node *root,*p;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &num[i]);
	for(i=1; i<=n; i++) {
		p=(Node*)malloc(sizeof(Node));
		cnt++;
		p->data=num[i];
		p->lchild=p->rchild=NULL;
		if(cnt==1) {
			p->deep=1;
			tree[cnt]=p;
			continue;
		}
		root=tree[1];
		for(;;) {
			if(num[i]<root->data) {
				if(root->lchild==NULL) {
					p->deep=root->deep+1;
					root->lchild=p;
					tree[cnt]=p;
					break;
				} else root=root->lchild;
			} else {
				if(root->rchild==NULL) {
					p->deep=root->deep+1;
					root->rchild=p;
					tree[cnt]=p;
					break;
				} else root=root->rchild;
			}
		}
	}
	preorder(tree[1]);
	return 0;
}


