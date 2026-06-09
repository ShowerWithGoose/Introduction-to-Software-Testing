#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAXINE 100
int top = -1; 
int stack[MAXINE];

int popstack(int stack[]);
int pushstack(int stack[], int item);
int isempty(int top);
int isfull(int top);

int main()
{
	int num, elem;
	while(scanf("%d", &num) != EOF)
	{
		if(num == -1)
			break;
		else
		{
			if(num == 0)
			{
				popstack(stack);
			}
			else if(num == 1)
			{
				scanf("%d", &elem);
				pushstack(stack, elem);
			}
		}
	} 
	return 0;
}

int isempty(int top){
	return top == -1;
}

int isfull(int top){
	return top == MAXINE - 1;
}

int popstack(int stack[])
{
	if(isempty(top) == 1)
	{
		//¶ÑÕ»Îª¿Õ£¬²Ù×÷Ê§°Ü 
		printf("error ");
		return 0;
	}
	else
	{
		printf("%d ", stack[top--]);
		return 1; 
	}
}

int pushstack(int stack[], int elem){
	if(isfull(top) == 1)
	{
		//¶ÑÕ»ÒÑÂú£¬²Ù×÷Ê§°Ü
		printf("error ");
		return 0; 
	}
	else
	{
		stack[++top] = elem;
		return 1;
	}
}



