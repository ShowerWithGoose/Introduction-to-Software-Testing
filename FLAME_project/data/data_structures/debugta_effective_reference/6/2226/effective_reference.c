#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 100

typedef struct{
	int data[MaxSize];
	int top;	
}stack; 

void init(stack* s);

bool push(stack* s, int x);

bool pop(stack* s, int x);

bool get(stack* s, int x);

int main(){
	stack s;
	bool flag;
	int operation,element;
	
	init(&s);
	while(1){
		scanf("%d",&operation);
		if(operation==-1){
			break;
		}
		else if(operation==1){
			scanf("%d",&element);
			flag=push(&s,element);
			if(flag==false){
				printf("error ");
			}
		}
		else if(operation==0){
			element=s.data[s.top];
			flag=pop(&s,element);
			if(flag==false){
				printf("error ");
			}
			else if(flag==true){
				printf("%d ",element);
			}
		}
	}
	return 0;
}

void init(stack* s){
	s->top=-1;
	return;
}

bool push(stack* s, int x){
	int operation;
	if(s->top==MaxSize-1){
		return false;
	}
	operation=s->top+1;
	s->top=operation;
	s->data[operation]=x;
	return true;
}

bool pop(stack* s, int x){
	int operation;
	if(s->top==-1){
		return false;
	}
	operation=s->top;
	x=s->data[operation];
	operation--;
	s->top=operation;
	return true;
}


bool get(stack* s, int x){
	int operation;
	if(s->top==-1){
		return false;
	}
	operation=s->top;
	x=s->data[operation];
	return true;
}



