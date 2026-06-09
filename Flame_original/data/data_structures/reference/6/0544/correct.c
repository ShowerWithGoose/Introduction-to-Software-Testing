#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100
int STACK[MAXSIZE];
int top = -1;


int ISEMPTY(int top)
{
	return (top == -1);
}

int ISFULL(int top)
{
	return (top == MAXSIZE - 1);
}

void PUSH(int STACK[], int *top, int item)//将item插入栈STACK
{
	if (ISFULL(*top))
		printf("error ");
	else
		STACK[++(*top)] = item;
}

void POP(int STACK[], int *top, int *itempop)//弹出栈顶元素存入itempop
{
	if (ISEMPTY(*top))
	{
		printf("error ");
		return;
	}
		
	else
	{
		*itempop = STACK[(*top)--];
		printf("%d ", *itempop);
	}	
}


int main()
{
	int itempop=0;
	int d[1000] = { 0 };
	int num=0;
	char c = ' ';
	int i = 0;
	while (1)
	{
		scanf("%d%c", &num, &c);
		if (c != '\n')
			d[i++] = num;
		else
		{
			d[i] = -1;
			break;
		}
	}
	for (int i = 0; d[i] != -1; i++)
	{
		if (d[i] == 1)
			PUSH(STACK, &top, d[i + 1]);
		else if (d[i] == 0)
		{
			POP(STACK, &top, &itempop);
		}
		else if (d[i] == -1)
			return 0;
	}
	return 0;
}
