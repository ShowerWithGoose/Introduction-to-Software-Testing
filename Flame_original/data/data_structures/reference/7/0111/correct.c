#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int num;
int n;
int i,h;

typedef struct node{
	int  data;
	struct node*lt,*rt;
}BTNode,*BTREE;

BTREE T=NULL;
void BuildBT(BTREE *p){
	if((*p)==NULL){
	   	(*p)=(BTREE)malloc(sizeof(BTNode));
		(*p)->data=num;
		(*p)->lt=(*p)->rt=NULL;
	}
	else if(num>=(*p)->data)BuildBT(&((*p)->rt));
	else if(num<(*p)->data)BuildBT(&((*p)->lt));
}

void Leafh(BTREE T,int h) {//计算叶子结点到根节点的高度
	if (!T) {
		return;
	}
	if (T->lt == NULL && T->rt == NULL) {
		printf("%d %d\n", T->data, h + 1);
	}
	else {
		Leafh(T->lt, h + 1);
		Leafh(T->rt, h + 1);
	}
}

int TreeDepth(BTREE *p) {
	if ((*p)== NULL) {
		return 0;
	}
	int depth = 0;
	int LeftDepth = TreeDepth(&((*p)->lt));
	int RightDepth = TreeDepth(&((*p)->rt));
	depth = LeftDepth > RightDepth ? LeftDepth + 1: RightDepth + 1;
	return depth;
}

int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num);
		BuildBT(&T);
	}
	Leafh(T,h);
    return 0;
}

