#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tree {
	int Item;
	int depth;
	struct tree *lchild,*rchild;
} BTREE;
BTREE *insert(int k,int depth, BTREE *root) {
	BTREE *p=(BTREE *)malloc(sizeof(BTREE));
	p->depth=depth;
	p->Item=k;
	p->lchild=p->rchild=NULL;
	if(root==NULL) {
		root = p;
		return root;
	} else {
		depth++;
		p->depth++;
		if(k<root->Item) {
			if(root->lchild==NULL) {
				root->lchild=p;
				return root;
			} else {
				root->lchild=insert(k,depth,root->lchild);
			}
		} else {
			if(root->Item<=k) {
				if(root->rchild==NULL) {
					root->rchild=p;
					return root;
				} else {
					root->rchild=insert(k,depth,root->rchild);
				}
			}
		}
	}
	return root;
}
void preorder(BTREE *root) {
	if(root!=NULL) {
		if(root->lchild==NULL&&root->rchild==NULL)
			printf("%d %d\n",root->Item,root->depth);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
int main() {
	int n,i,k;
	BTREE *root=NULL;
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d",&k);
		root=insert(k,1,root);
	}
	preorder(root);
	return 0;
}
/*100
50
25
12
47
75
62
87
150
125
138
175
162
189*/

