#include<stdio.h>
#include<stdlib.h>
struct element{
	int num;
	int h;
}data;
typedef struct BiTNode{
	struct element data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void preorder(BiTree t);
int main(){
	BiTree T=NULL;//不能对空指针的T->lchild等赋值 
	int n,x,i=0,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		BiTree p,q;
		p=(BiTree)malloc(sizeof(BiTNode));
		p->data.num=x;
		p->data.h=1;
		p->lchild=NULL;
		p->rchild=NULL;
		if(T==NULL){
			T=p;
		}
		else{
			q=T;
			for(j=0;j<=i;j++){  
				if(x<q->data.num){
					if(q->lchild==NULL){
						(p->data.h)++;
						q->lchild=p;
						break;
					}
					else{
						q=q->lchild;
						(p->data.h)++;
					}
				}
				else{
					if(q->rchild==NULL){
						(p->data.h)++;
						q->rchild=p;
						break;
					}
					else{
						q=q->rchild;
						(p->data.h)++;
					}
				}
			}
		}
	}
	preorder(T);
	return 0;
}
void preorder(BiTree t){
	if(t!=NULL){
		if(t->lchild==NULL&&t->rchild==NULL) printf("%d %d\n",t->data.num,t->data.h);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

