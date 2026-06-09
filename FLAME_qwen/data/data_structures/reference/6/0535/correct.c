#include<stdio.h>
#include<stdlib.h>
#define max 103
struct stack{
	int data[max];
	int top;
}s;
typedef struct stack stack; 
void initstack(stack *s){
	s->top=-1;
}
int pop(stack*s){
	if(s->top==-1){
	printf("error ");
	return 0;
    }
	printf("%d ",s->data[s->top--]);
	return 1;
}
int push(stack*s,int n){
	if(s->top==max-1){
	printf("error ");
	return 0;
    }
    s->data[++s->top]=n;
    return 1;
	
}
int main(){
	int op,life=1,n;
	initstack(&s);
	while(life&&scanf("%d",&op)){
		switch(op){
			case -1:life=0;break;
			case 1:scanf("%d",&n);push(&s,n);break;
			case 0:pop(&s);break;
		}
	}
	
	
	
	
	return 0;
}
	



