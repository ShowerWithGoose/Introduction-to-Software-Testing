#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 100

typedef struct{
	int data[MaxSize];
	int tt;	
}stack; 

void init(stack* stk);

bool push(stack* stk, int x);

bool pop(stack* stk, int x);

bool get(stack* stk, int x);

int main(){
	stack stk;
	bool flag;
	int op,x;
	
	init(&stk);
	while(1){
		scanf("%d",&op);
		if(op==-1){
			break;
		}
		else if(op==1){
			scanf("%d",&x);
			flag=push(&stk,x);
			if(flag==false){
				printf("error ");
			}
		}
		else if(op==0){
			x=stk.data[stk.tt];
			flag=pop(&stk,x);
			if(flag==false){
				printf("error ");
			}
			else if(flag==true){
				printf("%d ",x);
			}
		}
	}
	return 0;
}

void init(stack* stk){
	stk->tt=-1;
	return;
}

bool push(stack* stk, int x){
	int op;
	if(stk->tt==MaxSize-1){
		return false;
	}
	op=stk->tt+1;
	stk->tt=op;
	stk->data[op]=x;
	return true;
}

bool pop(stack* stk, int x){
	int op;
	if(stk->tt==-1){
		return false;
	}
	op=stk->tt;
	x=stk->data[op];
	op--;
	stk->tt=op;
	return true;
}


bool get(stack* stk, int x){
	int op;
	if(stk->tt==-1){
		return false;
	}
	op=stk->tt;
	x=stk->data[op];
	return true;
}



