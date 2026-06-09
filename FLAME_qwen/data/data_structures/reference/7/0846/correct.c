#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

typedef struct node{
	int num;
	struct node *lchild;
	struct node *rchild;
}BTNode,*BTNodeptr;
BTNodeptr list;


BTNodeptr insert(BTNodeptr,int);
void findl(BTNodeptr,int);
int main(int argc, char *argv[]) {
	int n,a;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		list=insert(list,a);
	}

	findl(list,1);
	
		return 0;
}

BTNodeptr insert(BTNodeptr t,int a){
	if(t==NULL){
		t=(BTNodeptr)malloc(sizeof(BTNode));
		t->num=a;
		t->lchild=t->rchild =NULL;
	} 
	else{
		if(a<t->num)t->lchild=insert(t->lchild,a);
		else t->rchild=insert(t->rchild,a);
	}
	return t;
}
void findl(BTNodeptr t,int d){
	if(t==NULL)return;
	if(t->lchild==NULL&&t->rchild==NULL)printf("%d %d\n",t->num,d);
	else {
		d++;
		findl(t->lchild,d);
		findl(t->rchild,d);
	}

}

