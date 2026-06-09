#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Tree{
 
	int data;
	int floor;
	struct Tree *lchild;
	struct Tree *rchild;
 
}Tree,*BitTree;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

BitTree CreatLink(int n){
	BitTree p,q,list=NULL;
	int i,floor;
	for(i=0;i<n;i++){
		q = (BitTree)malloc(sizeof(Tree));
		q->data = read();
		q->lchild = NULL;
		q->rchild = NULL;
		
		if(list==NULL){
			list=q;
			q=list;
			q->floor = 1;
		}
		else{
			for(floor=2,p=list;;floor++/*floor表示层数*/){
				if(q->data<p->data){
					if(p->lchild==NULL){ 
						p->lchild = q;
						q->floor=floor;
						break;
					} 
					if(p->lchild!=NULL){
						p=p->lchild;
						continue;
					}
				}
				if(q->data>=p->data){
					if(p->rchild==NULL){ 
						p->rchild = q;
						q->floor=floor;
						break;
					} 
					if(p->rchild!=NULL){
						p=p->rchild;
						continue;
					}
				}
			}
		}
	}
	return list;
}

void preorder(BitTree T){	//前序遍历 
	if(T==NULL) return;
	
	if(T->lchild==NULL&&T->rchild==NULL){
		printf("%d %d\n",T->data,T->floor);
	}
	preorder(T->lchild);
	preorder(T->rchild);
}

void inorder(BitTree T){	//中序遍历
	if(T==NULL) return;
	
	inorder(T->lchild);
	//if(T->lchild==NULL&&T->rchild==NULL){
		printf("%d %d\n",T->data,T->floor);
	//}
	inorder(T->rchild);
}

void postorder(BitTree T){	//后序遍历 
	if(T==NULL) return;
	
	postorder(T->lchild);
	postorder(T->rchild);
	//if(T->lchild==NULL&&T->rchild==NULL){
		printf("%d %d\n",T->data,T->floor);
	//}
}

int main(){
	int n;
	BitTree T;
	scanf("%d",&n);
	T = CreatLink(n);
	
	preorder(T);
	//preorder(T);
	//preorder(T);
	
	return 0;
} 

