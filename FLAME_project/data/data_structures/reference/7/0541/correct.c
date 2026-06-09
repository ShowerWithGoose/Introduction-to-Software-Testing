#include<stdio.h>
#include<stdlib.h>
typedef struct Tree {
	int value;
	struct Tree *l, *r;
}Tree; 

void insert(Tree **p, int x){
	if((*p) == NULL){
		(*p) = (Tree *)malloc(sizeof(Tree));
		(*p)->value = x;
		(*p)->l = NULL;
		(*p)->r = NULL;
	}
	
	else if(x < (*p)->value) insert(&((*p)->l), x);
	
	else insert(&((*p)->r), x);
	
	return;
}

void searchleaf(Tree **p,int x){
	if((*p)->l == NULL && (*p)->r == NULL){
		printf("%d %d\n", (*p)->value, x);
		return;
	}
	
	x++;
	if((*p)->l) searchleaf(&((*p)->l), x);
	if((*p)->r) searchleaf(&((*p)->r), x);
}

int main(){
	int n;
	
	int x;
	
	scanf("%d",&n);
	
	Tree *t = NULL;
	
	while(n--){
		scanf("%d",&x);
		insert(&t, x);
	}
	
	searchleaf(&t, 1);
}

