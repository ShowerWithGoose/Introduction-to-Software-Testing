#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct tree{
	int num;
	int height;
	struct tree *llink;
	struct tree *rlink;
};
typedef struct tree Tree,*Treeptr;

Tree *llink,*rlink,*head = NULL;

Treeptr build(Treeptr q,int n,int i){
	if(q == NULL){
		q = (Treeptr)malloc(sizeof(Tree));
		q -> num = n;
		q -> height = i;
		q -> llink = q -> rlink = NULL;
		head = q;
	}
	else if(n < q -> num){
		q -> llink = build(q -> llink,n,i + 1);
	}
	else if(n >= q -> num){
		q -> rlink = build(q -> rlink,n,i + 1);
	}
	return q;
}

void print(Tree *p){
	if(p != NULL){
		if(p -> llink == NULL&&p -> rlink == NULL){
			printf("%d %d\n",p -> num,p -> height);
		}
		print(p -> llink);
		print(p -> rlink);
	}
}

int main(){
	int N,n,i;
	Treeptr p = NULL;
	scanf("%d",&N);
	for(i = 0;i < N;i++){
		scanf("%d",&n);
		p = build(p,n,1);
	}
	
	print(p);
	return 0;
} 

