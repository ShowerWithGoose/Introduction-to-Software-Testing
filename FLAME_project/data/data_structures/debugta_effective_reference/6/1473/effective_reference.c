#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h> 
#define Maxsize 100
typedef struct SqStack
{
	int data[Maxsize];
	int top;
}SqStack;
SqStack *S;
SqStack *InitStack()
{
	SqStack *S;
	S = (SqStack *)malloc(sizeof(struct SqStack));
	S -> top = -1;
	return S;
}
void push(SqStack *S, int x)
{
	if(S->top == Maxsize - 1)
	{
		printf("error ");
	}
	else
	{
		S->data[S->top] = x;
		S->top++;		
	}
	
}
void pop(SqStack *S,int x)
{
	if(S -> top == -1)
	{
		printf("error ");
	}
	else
	{
		printf("%d ", S->data[x - 2]);
		S -> top--;
	}	
} 
void output(SqStack *S,int top)
{
	int i;
	for(i = top - 1;i >= 0;i --)
	{
		printf("%d ", S->data[i]);
	}
}
int main()
{
	int jud[200];
	int i = 0;
	for(i = 0;i <= 300;i ++)
	{
		if(jud[i - 1] == -1)
		{
			break;
		}
		else
			scanf("%d",&jud[i]);
		
	} 
	SqStack *S = InitStack();
	int x = i -1;
	int b[200];
	int j = 0;
	for(i = 0;i <= x;i ++)
	{	
		if(jud[i] == 0)
		{
			pop(S,j);
			j --;
			if(j < 0)
			{
				j = 0;
			}
		}
		if(jud[i] == -1)
		{
			break;
		}
		if(jud[i] == 1)
		{
			push(S,jud[i+1]);
			i++;
			j++;
		}
	}
	//output(S,j);
}



