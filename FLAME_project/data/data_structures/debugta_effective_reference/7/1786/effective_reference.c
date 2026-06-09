#include <stdio.h>
#include <stdlib.h>
struct tree{
	struct tree *lchild;
	int num;
	struct tree *rchild;
	int depth;
};
void bianli(struct tree*r){
	if(r!=NULL){
	if(r->lchild==NULL&&r->rchild==NULL)
	printf("%d %d\n",r->num,r->depth);
	bianli(r->lchild);
	bianli(r->rchild);}
}
int main(){
	struct tree *root=NULL,*p,*q=NULL;
	int n;
	scanf("%d",&n);
	int x;
	int height=0;
	while(n--){
		scanf("%d",&x);
		if(root==NULL){
			p=(struct tree*)malloc(sizeof(struct tree));
			p->num=x;
			p->depth =1;
			p->lchild =NULL;
			p->rchild =NULL;
			root=p;
		}
		else{
			if(x<root->num){
				p=root;
				q=root->lchild;
				while(q!=NULL){
					if(x<q->num){
						p=q;
						q=q->lchild;
					}
					else{
						p=q;
						q=q->rchild ;
					}
					height++;
				}
				q=(struct tree*)malloc(sizeof(struct tree));
				q->num =x;
				q->depth=height+2;
				q->lchild =NULL;
				q->rchild =NULL;
				if(x<p->num)
				p->lchild =q;
				else
				p->rchild =q;
			}
			if(x>=root->num){
				p=root;
				q=root->rchild ;
				while(q!=NULL){
					if(x<q->num){
						p=q;
						q=q->lchild;
					}
					else{
						p=q;
						q=q->rchild ;
					}
					height++;
				}
				q=(struct tree*)malloc(sizeof(struct tree));
				q->num =x;
				q->depth=height+2;
				q->lchild =NULL;
				q->rchild =NULL;
				if(x<p->num)
				p->lchild =q;
				else
				p->rchild =q;
			}
		}
		height=0;
	}
	bianli(root);
	return 0;
}



