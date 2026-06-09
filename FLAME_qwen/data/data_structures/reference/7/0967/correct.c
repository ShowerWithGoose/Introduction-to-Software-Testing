#include <stdio.h>
#include <stdlib.h>
typedef struct gg{
	int atom;
	struct gg *lchild,*rchild;
}tree;
void inorder(tree *p,int n){
	if(p->lchild==NULL&&p->rchild==NULL){
		printf("%d %d\n",p->atom,n);
	}else{
		if(p->lchild!=NULL)
			inorder(p->lchild,n+1);
		if(p->rchild!=NULL)
		inorder(p->rchild,n+1);
	}
}
int main(){
	int n,i,m;
	tree *root=NULL,*p,*q;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		if(root==NULL){
			root=(tree*)malloc(sizeof(tree));
			root->atom=m;
			root->lchild=root->rchild=NULL;
		}else{
			p=root;q=(tree*)malloc(sizeof(tree));
			q->lchild=q->rchild=NULL;
			while(p!=NULL){
				if(m<p->atom&&p->lchild==NULL){
					p->lchild=q;
					q->atom=m;
					break;
				}else{
					if(m>=p->atom&&p->rchild==NULL){
						p->rchild=q;
						q->atom=m;
						break;
					}
				}
				if(m<p->atom){
					p=p->lchild;
				}else{
					p=p->rchild;
				}
			}	
			
		}
	}
	inorder(root,1);
	return 0;
}


