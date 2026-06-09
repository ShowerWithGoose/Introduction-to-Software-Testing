#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
int stack[MAXSIZE];
int top = -1;

void push(int n);
void pop();

int main()
{
    int a, b;
    while(1)
    {
        scanf("%d",&a);
		if(a==1)
		{
			scanf("%d",&b);
            push(b);
           
		}
		else if(a==0)
		{
			pop();
			
		}
		else if(a=-1)
		return 0;
    }
}

void push(int num)
{
    if(top == MAXSIZE-1)
        printf("error ");
    else
        stack[++top] = num;
}

void pop()
{
    if(top == -1)
        printf("error ");
    else
        printf("%d ",stack[top--]);
}



