#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct stack
{
	int top;
	int* num;
}Stack;

Stack* makeStack()
{
	Stack* S = (Stack*)malloc(sizeof(Stack));
    S->top = -1;
    S->num = (int*)malloc(100*sizeof(int));
    return S; 
}
int main()
{
	int n,x;
	Stack* S = makeStack();
	scanf("%d",&n);
	while(n!=-1)
	{
		if(n==1)
		{
			scanf(" %d",&x);
			if(S->top>=100)
			{
				printf("error ");
			}
			else 
			{   S->top++;
				S->num[S->top]=x;
				//S->top++;
			}
		}
		else if(n==0)
		{
			if(S->top<0)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",S->num[S->top]);
				S->top--;
			}	
		}
		scanf("%d",&n);
	}
	return 0;
}

