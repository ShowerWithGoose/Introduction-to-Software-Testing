#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXLINE 1024
#define eps 1e-15

#define MAXSIZE 100
typedef int ElemType;

ElemType stack[MAXSIZE];
int top;

void initStack()
{
	top = -1;
} 
void push(ElemType s[], ElemType a)
{
	if(top == MAXSIZE - 1)
		printf("error ");
	else 
		s[++top] = a;
}

void pop(ElemType s[])
{
	if(top == -1)
		printf("error ");
	else
		printf("%d ", s[top--]);
}

int main(){
	initStack();
	int key,num;
	while(scanf("%d",&key))
	{
		if(key == -1)
			break;
		else if(key == 1)
		{
			scanf("%d",&num);
			push(stack, num);
		}
		else
			pop(stack);	
	}

	return 0;
}


