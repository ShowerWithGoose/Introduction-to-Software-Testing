#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	int depth;
	struct node *lchild;
	struct node *rchild;
};
typedef struct node BTNode, *BTREE;
int n=0,num=0,depth=1;
BTREE root=NULL;

BTREE INSERTBST(BTREE p,int num,int depth);
int isleave(BTREE p);
void shuchu(BTREE p);

int main(){
	int i=0;
	scanf("%d",&n );
	for(i=0;i<n;i++){
		scanf("%d", &num );
		root=INSERTBST(root,num,1);
	}
	shuchu(root);
	
	return 0; 
}    //

BTREE INSERTBST(BTREE p,int num,int depth){
	if(p==NULL){
		p=(BTREE)malloc(sizeof(BTNode));
		p->data=num;
		p->depth=depth;
		p->lchild=NULL;
		p->rchild=NULL;
		
	}
	else if(num<p->data){
		p->lchild=INSERTBST(p->lchild,num,depth+1);
	}  
	else if(num>=p->data){
		p->rchild=INSERTBST(p->rchild,num,depth+1);
	}
	
	return p;
}     //建立二叉查找树  （节点，要存入的数字，深度） 

int isleaf(BTREE p){
	if(p->lchild==NULL&&p->rchild==NULL){
		return 1;
		
	}
	else {
		return 0;
	}
}     //判断该节点是否为叶节点

void shuchu(BTREE p){
	if(p->lchild!=NULL){
		shuchu(p->lchild);
	}
	if(isleaf(p)==1){
		printf("%d %d\n", p->data, p->depth); 
	}
	if(p->rchild!=NULL){
		shuchu(p->rchild);
	}    //注意：不能用else if，因为对每个节点左中右都要验证，若有else，则每个节点只对一种情况验证（这就是树的结构特性）            
}      //输出函数：递归：若左或右节点不为叶节点，则对其进行又一次的递归  

