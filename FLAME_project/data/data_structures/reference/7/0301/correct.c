#include<stdio.h>
#include<stdlib.h>
struct tree{
	int data;
	int depth;
	struct tree *lc,*rc;
}; 
struct tree *root=NULL;
void creathead(int n){
	root=(struct tree*)malloc(sizeof(struct tree));
	root->data=n;
	root->depth=1;
	root->lc=root->rc=NULL;
}

struct tree * newNode(int n, int depth){
	struct tree *p;
	p=(struct tree*)malloc(sizeof(struct tree));
	p->data=n;
	p->depth=depth;
	p->lc=p->rc=NULL;
	return p; 
};
void order(struct tree *p,int n,int depth){
	depth++;
	if(p!=NULL){
		if(p->data>n){
			if(p->lc == NULL){
				p->lc = newNode(n, depth); 
			}else
				order(p->lc,n,depth);
		}
		else if(p->data<=n){
			if(p->rc==NULL){
				p->rc=newNode(n,depth);
			}
			else
			order(p->rc,n,depth);
		}
	}
}
void inorder(struct tree *p){
	if(p->lc!=NULL&&p->rc!=NULL){
		inorder(p->lc);
		inorder(p->rc);
	}
	else if(p->lc!=NULL){
		inorder(p->lc);
	}
	else if(p->rc!=NULL){
		inorder(p->rc);
	}
	else{
		printf("%d %d\n",p->data,p->depth);
		return ;
	}
}
int main(){
	int n,i;
	scanf("%d",&n);
	int a[100];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(i==0)
			creathead(a[i]);
		else
			order(root,a[i],1);
	}
	inorder(root);
	return 0;
}



