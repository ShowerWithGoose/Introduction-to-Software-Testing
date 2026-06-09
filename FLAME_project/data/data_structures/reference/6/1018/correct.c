#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
typedef struct{
	int num[100];
	int top;
}stacK;
void getin(stacK *stack);
void getout(stacK *stack);

int main(){
int judge;
stacK *stack;
stack = (stacK*)malloc(sizeof(stacK));
stack->top = -1;
while(scanf("%d",&judge) != EOF){
	if(judge == 1)getin(stack);
	else if(judge == 0)getout(stack);
	else break;
}
free(stack);
return 0;
} 

void getout(stacK *stack){
	if(stack->top == -1){
		printf("error ");
		return;
	}
	printf("%d ",stack->num[stack->top]);
	stack->num[stack->top] = 0;
	stack->top -= 1;
	return;
}

void getin(stacK *stack){
	int num;
	scanf("%d",&num);
	if(stack->top == 99){
		printf("error ");
		return;
	}
	stack->top += 1;
	stack->num[stack->top] = num;
	return;
}

