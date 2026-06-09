#include <stdio.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top;

void initstack()
{
	top = -1;
}

int isempty()
{
	return top == -1;
}

int isfull()
{
	return top == MAXSIZE-1;
}

void push(int s[ ], int item)
{
    if(isfull())
        printf("error ");
    else
    	s[++top] = item;
}

void pop(int s[])
{
    if(isempty())
        printf("error ");
    else
		printf("%d ", s[top--]);
}

int main()
{
	int op, item;
	initstack();
	do{
		scanf("%d", &op);
		if(op == 1){
			scanf("%d", &item);
			push(stack, item);
		}
		else if(op == 0){
			pop(stack);
		}
	}while(op != EOF);
	return 0;
} 

