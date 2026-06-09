#include<stdio.h>
#include<stdlib.h>
typedef struct mode{
	int data;
	int wz;
	struct mode *rchild,*lchild,*parent;
}mood;
mood **stack;
int top=-1;
int main(){
	int m,i=0,n,j=0;
	mood *list,*p,*q;
	list=NULL;
	scanf("%d",&n);
	stack=(mood**)malloc(n*sizeof(mood*));
	for(i=0;i<n;i++){
		scanf("%d",&m);
		j=1;
		p=(mood*)malloc(sizeof(mood));
			p->data=m;
			p->lchild=NULL;
			p->rchild=NULL;
		if(list==NULL){
			p->parent=NULL;
			p->wz=1;
			list=p;
		}else{
			q=list;
			while(1){
				j++;
				if(q->data>m){
					if(q->rchild==NULL){
						q->rchild=p;
						p->wz=j;
						p->parent=q;
						break;
					}else{
						q=q->rchild;
					}
				}else{
					if(q->lchild==NULL){
						q->lchild=p;
						p->wz=j;
						p->parent=q;
						break;
					}else{
						q=q->lchild;
					}
				}
			}
		}
	}
	p=list;
	do{
		for(;p!=NULL;p=p->rchild){
			stack[++top]=p;
		}p=stack[top--];
		if(p->lchild==NULL&&p->rchild==NULL){
			printf("%d %d\n",p->data,p->wz);
		}
		p=p->lchild;
	}while(p!=NULL||top!=-1);
	return 0;
} 

