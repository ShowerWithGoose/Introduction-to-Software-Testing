#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define M 100007
#define N 1007
#define INF 0x3f3f3f3f
#define ll long long
#define db	double
typedef struct node{
	int val,high;
	struct node *l,*r;
}Node;
Node *root;
Node* check(Node *t,int w,int len){
	len++;
	if(t==NULL){
		t=(Node*)malloc(sizeof(Node));
		t->val=w,t->l=NULL,t->r=NULL;
		t->high=len;
	}
	else if(w>=t->val){
		t->r=check(t->r,w,len);
	}
	else{
		t->l=check(t->l,w,len);
	}
	return t;
}
void print(Node* t){
	if(t!=NULL){
		if(t->l==NULL&&t->r==NULL){
			printf("%d %d\n",t->val,t->high);
		}
		print(t->l);
		print(t->r);
	}
}
int main() {
	int i,n,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		int len=0;
		scanf("%d",&ans);
		root=check(root,ans,len);
	}
	print(root);
	return 0;
}
//13
//50 38 30 64 58 40 10 73 70 50 60 100 35









