#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define MAX 100
struct SNode{
	int data[MAX];
	int top;
}; 
typedef struct SNode *stack;
void push(stack ptrs,int item){
	if(ptrs->top==MAX-1) printf("error ");
	else{
		ptrs->data[++ptrs->top]=item;
	}
}
void pop(stack ptrs){
	if(ptrs->top==-1) printf("error ");
	else{
		printf("%d ",ptrs->data[(ptrs->top)--]);
	}
}
int main(){
	int op,item;
	stack ptrs=malloc(sizeof(struct SNode));
	ptrs->top=-1;
	while(1){
		scanf("%d",&op);
		if(op==-1) break;
		if(op==1){
			scanf("%d",&item);
			push(ptrs,item);
		} 
		if(op==0) pop(ptrs);
	}
	return 0;
}


