#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef int Datatype;
struct node {
	Datatype data;
	int floor;
	struct node *lchild,*rchild;
}; 
typedef struct node BTNode,*BTNodeptr;
BTNodeptr root=NULL;//root为全局变量 
void insertBST(Datatype item){//二叉查找树的建立,小于节点左孩子，大于等于节点右孩子 
	BTNodeptr p,q;
	p=(BTNodeptr)malloc(sizeof(BTNode));//建立新结点 
	p->data=item;p->floor=1;
	p->lchild=NULL;
	p->rchild=NULL;
	int count=1;
	if(root==NULL) root=p;
	else{
		q=root;
		while(1){
			if(item<q->data){
				if(q->lchild==NULL){
					q->lchild=p;       q->lchild->floor+=count;    count=1;
					break;
				}else{
					q=q->lchild;count++;
				}
			}
			else{
				if(q->rchild==NULL){
					q->rchild=p;      q->rchild->floor+=count;   count=1;
					break;
				}else{
					q=q->rchild;count++;
					}
				}
		}
	}
}
	
void printleaf(BTNodeptr t){

	if(t==NULL) return ;
	if(t->lchild==NULL&&t->rchild==NULL){
		printf("%d %d\n",t->data,t->floor);
	
	}

	
	printleaf(t->lchild);
	printleaf(t->rchild);
} 
int main(){
int n,item,i;
scanf("%d",&n);
for(i=0;i<n;i++){
	scanf("%d",&item);
	insertBST(item);
}
printleaf(root);
	return 0;
}



