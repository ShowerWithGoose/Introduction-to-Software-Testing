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
	BiTree t=NULL;//不能对空指针的T->lchild等赋值 
	int num,n,i=0,depth;
	scanf("%d",&num);
	for(i=0;i<num;i++){
		scanf("%d",&n);
		BiTree p,q;
		p=(BiTree)malloc(sizeof(BiTNode));
		p->data.num=n;
		p->data.h=1;
		p->lchild=NULL;
		p->rchild=NULL;
		if(t==NULL){
			t=p;
		}
		else{
			q=t;
			for(depth=0;depth<=i;depth++){  
				if(n<q->data.num){
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
	preorder(t);
	return 0;
}
void preorder(BiTree t){
	if(t!=NULL){
		if(t->lchild==NULL&&t->rchild==NULL) printf("%d %d\n",t->data.num,t->data.h);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

