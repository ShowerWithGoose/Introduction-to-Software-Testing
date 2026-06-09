#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
struct stack{
	int data[100];
	int top;
} stack1;
typedef struct stack* stackptr;
int Push(stackptr s,int a)
{
	if(s->top>=99){
		printf("error ");
		return 1;
	}
	else{
		s->top++;
		s->data[s->top]=a;
		return 0;
	}
}
int Pop(stackptr s){
	if(s->top<0){
		printf("error ");
		return -1;
	}
	else{
		printf("%d ",s->data[s->top]);
		s->data[s->top]=0;
		s->top--;
		return 0;
	}
}
int main()
{
	int order,num;
	stack1.top=-1;
	while(scanf("%d",&order),order>=0){
		if(order==1){
			scanf("%d",&num);
			Push(&stack1,num);
		}
		else Pop(&stack1);
	}
	return 0;
}



