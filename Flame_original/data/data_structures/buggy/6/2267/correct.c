#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Maxsize 100
void push(int *stack,int a);
int pop(int *stack);
int top=-1;
int main()
{
	int stack[Maxsize];
	int op,num;
	

	while(1)
	{
		scanf("%d",&op);
		if (op==-1)
		break;
	    else
	    {
	    	 if (op==1)
		{
				scanf("%d",&num);
				if (top==Maxsize-1)
				{
					 printf("error ");
				}
	           
			   else
			   {
			   	push(stack,num);
			   }
		}
		else if (op==0)
		{
			if (top==-1)
			{
				printf("error ");
			}
	        else
	        {
	        	int q;
			q=pop(stack);
			printf("%d ",q);
			}
		}  
		}
	}
	
	
	return 0;
}

void push(int *stack,int a)
{
	stack[++top]=a;
	
}
int pop(int *stack)
{
	
	
		int a=stack[top];
		top--;
		return a;
	
}



