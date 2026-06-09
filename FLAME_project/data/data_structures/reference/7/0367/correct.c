#include <stdio.h>
#include <stdlib.h>
struct node {
	int num;
	int h;//层次
	struct node *left,*right;
};
void postorder(struct node *t) { //后序遍历
	if(t!=NULL) {
		postorder(t->left);
		postorder(t->right);
		if(t->left==NULL&&t->right==NULL) {
			printf("%d %d\n",t->num,t->h);
		}
	}
}
int main() {
	int n,m;
	int i;
	scanf("%d",&n);
	struct node *root=NULL,*p,*q;
	for(i=1; i<=n; i++) {
		scanf("%d",&m);
		p=(struct node *)malloc(sizeof(struct node));
		p->num=m;
		p->right=NULL;
		p->left=NULL;
		p->h=1;//根
		if(root==NULL)
			root=p;
		else {
			q=root;
			while(1) {
				if(m<q->num) {
					if(q->left==NULL) 
					{
						q->left=p;
						(p->h)++;//层数加一
						break;
					} 
					else 
					{
						q=q->left;
						(p->h)++;
					}
				} 
				else {
					if(q->right==NULL) 
					{
						q->right=p;
						(p->h)++;
						break;
					} 
					else 
					{
						q=q->right;
						(p->h)++;
					}
				}
			}
		}
	}
	postorder(root);
	return 0;
}

