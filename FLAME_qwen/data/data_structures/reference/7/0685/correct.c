#include<stdio.h>
#include<stdlib.h>
struct BST{
	int num;
	int height;
	struct BST *llink;
	struct BST *rlink;
}ROOT;
struct BST *root=&ROOT;
void BST_insert(int key){
	struct BST *p=root,*r=root;
	struct BST *q=(struct BST *)malloc(sizeof(struct BST));
	q->llink=NULL;
	q->rlink=NULL; 
	int height=1;
	while(1){
		height++;
		if(key < p->num){
			if(p->llink!=NULL)
				p=p->llink;		
			else {
				p->llink=q;
				q->num=key;
				q->height=height;
				return;
			}		
		}
		else{
			if(p->rlink!=NULL)
				p=p->rlink;
			else {
				p->rlink=q;
				q->num=key;
				q->height=height;
				return;
			}
		}	
	}	
}
void *mid(struct BST *p){
	if(p!=NULL){
		mid(p->llink);
		if(p->llink==NULL&&p->rlink==NULL)
			printf("%d %d\n",p->num,p->height);
		mid(p->rlink); 
	}
} 
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int m;
		scanf("%d",&m);
		if(i==1){
			root->num=m;
			root->height=1;
		}	
		else 
			BST_insert(m);
	}
	mid(root);
	return 0;
} 



