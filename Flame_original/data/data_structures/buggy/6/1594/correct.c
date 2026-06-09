#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
ElemType Stack[MAXSIZE];
int top=-1;

void push(ElemType s[], ElemType item);
void pop(ElemType s[]);


int isFull();
int isEmpty();
int main()
{
	int op;	
	int input;

	while(scanf("%d",&op)!=-1)
	{
		if(op==1)
    	{
    		scanf("%d",&input);
    		push(Stack,input);
    		
    	}
		else if(op==0)
    	{
    		pop(Stack);
    		
    	}
    	else
    	{
    		return 0;
		}
	}
	
	return 0;
	
}
void push(ElemType s[], ElemType item)
{
    if (isFull())
    {
	    printf("error ");
	}
    else
    {
    	s[++top]=item;
	}
}
void pop(ElemType s[])
{
    if(isEmpty())
    {
    	printf("error ");
	}
    else
    {
    	printf("%d ",s[top]);
    	top--;
	}
}
int isFull()
{
    return top==MAXSIZE-1;
}
int isEmpty()
{
    return top==-1;
}


