#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define M 102
struct stack{
	int data[M];
	int top;
}s;
typedef struct stack list;
int in,a;
void INITIAL(list *s){
	s->top = -1;
}
int EMPTY(list *s){
	return s->top == -1;
}
int FULL(list *s){
	return s->top == M - 1;
}
int PUSH(list *s,int in){
	if(FULL(s)){
		printf("error ");//Õ»Âú
		return 0; 
	}
	s->data[++s->top] = in;
	return 1;
}
int POP(list *s,int in){
	if(s->top == -1){
		printf("error ");
		return 0;
	}

	in = s->data[s->top--];
	printf("%d ",in);
	return 1;

}
int main(void){
	int op = -1;
	INITIAL(&s);
	while(1){
		scanf("%d",&op);
		if(op == -1){
			break;
		}
		else if(op == 0){
			POP(&s,in);
		}
		else if(op == 1){
			scanf("%d",&a);
			PUSH(&s,a);
		}
	}
}

