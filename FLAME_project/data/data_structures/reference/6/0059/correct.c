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
	int a,b;
	
	init(&s);
	while(1){
		scanf("%d",&a);
		if(a==-1){
			break;
		}
		else if(a==1){
			scanf("%d",&b);
			flag=push(&s,b);
			if(flag==false){
				printf("error ");
			}
		}
		else if(a==0){
			b=s.data[s.top];
			flag=pop(&s,b);
			if(flag==false){
				printf("error ");
			}
			else if(flag==true){
				printf("%d ",b);
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
	int a;
	if(s->top==MaxSize-1){
		return false;
	}
	a=s->top+1;
	s->top=a;
	s->data[a]=x;
	return true;
}

bool pop(stack* s, int x){
	int a;
	if(s->top==-1){
		return false;
	}
	a=s->top;
	x=s->data[a];
	a--;
	s->top=a;
	return true;
}


bool get(stack* s, int x){
	int a;
	if(s->top==-1){
		return false;
	}
	a=s->top;
	x=s->data[a];
	return true;
}



