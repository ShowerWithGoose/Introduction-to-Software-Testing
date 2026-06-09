#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define MAXSIZE     1000
typedef struct stack
{
	int data[200];
    int top;
} stack;
stack s;
int a;
void init( stack *s)
{
        s->top = -1;
}
int  isEmpty( stack *s)
{
       return s->top==-1;
} 
int isFull( stack *s )
{
      return s->top==200-1;
}

int push( stack *s,int a)
{   	if( isFull(s)!=0 )
           {
			printf("error ");
            return 0;
			}
    
       	s->data[++s->top] = a;
    	return 1;

      }
int pop(stack *s, int a)
{
    if (s->top == -1)
    {
        printf("error ");
        return 0;
    }
    a = s->data[s->top--];
    printf("%d ", a);
    return 1;
}

int main()
{
	int a,b;
	stack st;
	init(&st);
	while(scanf("%d",&a)!=-1)
	{
		
		if(a==1)
		{
			scanf("%d",&b);
			push(&st,b);
		}
		if(a==0)
		{
			pop(&st,a);
		}
	}

	return 0;
}

