#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 100

typedef int ElementType, Position;
struct SNode{
	ElementType *Data;
	Position Top;
	int MaxSize;
};

typedef struct SNode *Stack;

Stack CreatStack(int MaxSize)
{
	Stack S = (Stack)malloc(sizeof(Stack));
	S -> Data = (ElementType*)malloc(MaxSize * sizeof(ElementType));
	S -> Top = -1;
	S -> MaxSize = MaxSize;
	return S;
}

bool IsFull(Stack S)
{
	return (S -> Top == S -> MaxSize - 1);
}

bool IsEmpty(Stack S)
{
	return (S -> Top == -1);
}

int Push(Stack S,ElementType X)
{
	if(IsFull(S))
	{
		printf("Full-ed");
		return 0;
	}
	else
	{
		S -> Data[++(S -> Top)] = X;
		return 1;
	}
}

int Pop(Stack S)
{
	while(!IsEmpty(S))
	{
		return (S -> Data[(S -> Top)--]);	
	}
	printf("error ");
	return (S -> Top);
}

int main()
{
	Stack num;
	num = CreatStack(MAX);
	int a=0, b=0, c=0;
	while(scanf("%d", &a))
	{
		if(a == -1)
			return 0;
		if(a == 1)
		{
			scanf("%d", &b);
			Push(num,b);
		}
		else
		{
			c = Pop(num);
			if(c != -1)
				printf("%d ", c);
		}
	}
	return 0;
}


