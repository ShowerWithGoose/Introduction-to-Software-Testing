#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node{
	int data;
	struct node *lchild,*rchild;
	int line;
}bt;
typedef struct node *BT;
/*或者 
struct node{
	int data;
	struct node *lchild,*rchild;
	int line;
};
typedef struct node bt;
typedef struct node *BT;

再或者 
typedef struct node{
	int data;
	struct node *lchild,*rchild;
	int line;
}bt,*BT;
*/
///   凡是BT,bt前，加上typedef 
BT root;
BT buildtree(BT t,int n,int cnt);
void print(BT t);
int main(){
	int n=0,num,cnt=0,i=0;
	BT t=NULL;
	BT p,q=NULL;
	scanf("%d",&num);
	for(i=0;i<num;i++){
		scanf("%d",&n);
		cnt=0;
		t=buildtree(t,n,cnt);
	}
	print(t);
	return 0;
}
BT buildtree(BT t,int n,int cnt){
	cnt++;
	if(t==NULL){
		t=(BT)malloc(sizeof(bt));
		t->data=n;
		t->lchild=t->rchild=NULL;
		t->line=cnt;
	}
	else if(n<t->data){
		t->lchild=buildtree(t->lchild,n,cnt);
	}
	else if(n>=t->data){
		t->rchild=buildtree(t->rchild,n,cnt);
	}
	return t;
}
void print(BT t){
	if(t!=NULL){
		if(t->lchild==NULL&&t->rchild==NULL)
		printf("%d %d\n",t->data,t->line);
		print(t->lchild);
		print(t->rchild);
	}
}

