#include <stdio.h>

struct st_stack{
	int data[102];
	int top;
};
typedef struct st_stack stack;
int a;
stack s;

void initStack(stack *s){//初始化栈 
	s->top=-1;
}

int isEmpty(stack *s){//判断栈空 
	return s->top==-1;
}

int isFull(stack *s){
	return s->top==99;
}

int push(stack *s, int a){//进栈 
	if(isFull(s)==1){
		printf("error ");
		return 0;//满了 
	}
	else{
		s->data[++s->top]=a;//让a进栈 
	}
	return 0;
}

int pop(stack *s, int a){
	if(isEmpty(s)==1){
		printf("error ");
		return 0;//空了 
	}
	else{
		a=s->data[s->top--];
		printf("%d ",a);
	}
	return 0;
}

int main(){
	int num;
	int control=-1;
	initStack(&s);//初始化栈
	while(1){//无限输入 
		scanf("%d",&control);
		if(control==-1){
			break;
		}
		else if(control==0){//出栈 
			pop(&s,a);
		}
		else if(control==1){
			scanf("%d",&num);
			push(&s,num);
		}
	} 
	return 0;
}

