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
	int m;
	scanf("%d",&m);
	int n;
	int cnt=0;
	while(m--){
		scanf("%d",&n);
		if(root==NULL){
			p=(struct tree*)malloc(sizeof(struct tree));
			p->num=n;
			p->depth =1;
			p->lchild =NULL;
			p->rchild =NULL;
			root=p;
		}
		else{
			if(n<root->num){
				p=root;
				q=root->lchild;
				while(q!=NULL){
					if(n<q->num){
						p=q;
						q=q->lchild;
					}
					else{
						p=q;
						q=q->rchild ;
					}
					cnt++;
				}
				q=(struct tree*)malloc(sizeof(struct tree));
				q->num =n;
				q->depth=cnt+2;
				q->lchild =NULL;
				q->rchild =NULL;
				if(n<p->num)
				p->lchild =q;
				else
				p->rchild =q;
			}
			if(n>=root->num){
				p=root;
				q=root->rchild ;
				while(q!=NULL){
					if(n<q->num){
						p=q;
						q=q->lchild;
					}
					else{
						p=q;
						q=q->rchild ;
					}
					cnt++;
				}
				q=(struct tree*)malloc(sizeof(struct tree));
				q->num =n;
				q->depth=cnt+2;
				q->lchild =NULL;
				q->rchild =NULL;
				if(n<p->num)
				p->lchild =q;
				else
				p->rchild =q;
			}
		}
		cnt=0;
	}
	bianli(root);
	return 0;
}



