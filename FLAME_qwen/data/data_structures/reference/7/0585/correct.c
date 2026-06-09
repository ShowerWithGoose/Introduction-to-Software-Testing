#include<stdio.h>
#include<stdlib.h>
typedef struct line {
	int x;
	struct line *left,*right;
} xr;
xr*Creat( xr *root,int m);
void shuchu(xr *root,int j);
int main() {
	int n,m,j=1;
	xr *root;
	root=(xr*)malloc(sizeof(xr));
	root=NULL;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&m);
		root=Creat(root,m);
	}
	shuchu(root,j);
}
xr *Creat( xr *root,int m) {
	if(root==NULL) {
		root=(xr*)malloc(sizeof(xr));
		root->x=m;
		root->right=NULL;
		root->left=NULL;
	} else {
		if(m<root->x) root->left=Creat(root->left,m);
		else if(m>=root->x) root->right=Creat(root->right,m);
	}
	return root;
}
void shuchu(xr *root,int j) {
	if(root->left==NULL&&root->right==NULL) {
		printf("%d %d\n",root->x,j);
	} else {
		if(root->left!=NULL) {
			shuchu(root->left,j+1);
		}
		if(root->right!=NULL)
			shuchu(root->right,j+1);
	}
}
