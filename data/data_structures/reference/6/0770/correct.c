#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int val;
	struct node *pnext;
}ele;
int cnt=0;
ele *top;	//top is headnode
void push(ele*);
void pop(ele*);
int main(){
	top=(ele*)malloc(sizeof(ele));
	top->pnext = NULL;
	int op;
	ele *r=top;		//r is bottom
	while(scanf("%d", &op) != EOF){
		if(1==op){
			push(r);
			//push
		}
		else if(0==op){
			pop(r);
			//pop
		}
		else if(-1==op)
			return 0;
	}
	printf("strangely ending");
	return 0;
}
void push(ele *r){
	if(cnt>=100){
		printf("error ");
		return;
	}
	ele *newnode=(ele*)malloc(sizeof(ele));
	scanf("%d", &(newnode->val));
	newnode->pnext = top->pnext;
	top->pnext = newnode;
	cnt++;
	return;
}
void pop(ele *r){
	if(top->pnext != NULL){
		printf("%d ", top->pnext->val);
		ele *temp=top->pnext;
		top->pnext = top->pnext->pnext;
		free(temp);
		return;
	}
	printf("error ");
	return;		
}

