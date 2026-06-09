#include<stdio.h>
struct stack{
	int num[102];
	int top;
}s;
typedef struct stack stack;

void initialStack(stack *s){
	s->top = -1;
}

int isFull(stack *s){
	if(s->top == 101 )  return 1;
	else return 0;
}

int isEmpty(stack *s){
	if (s->top == -1 )   return 1;
	else return 0;
}

int push(stack *s){
	if( isFull (s) ) {
		printf("error ");
		return 0;
	}
	else{
		int a;
		scanf("%d",&a);
		s->num [++s->top ]  = a;
		return 1;
	}
}


int pop(stack *s){
	if( isEmpty(s) ){
		printf("error ");
		return 0; 
	}
	else printf("%d ",s->num[s->top--] );
}



int main(){
	initialStack(&s);
	int n;
	while(1){
		scanf("%d",&n);
		if(n == -1)  break;
		if(n == 0 ) pop(&s);
		if(n == 1) push(&s);
	}
	return 0;
}









