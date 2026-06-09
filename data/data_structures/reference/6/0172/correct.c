#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

int stack[MAXSIZE];
int top=-1;   
void in_stack(int item)
    {
        if(top==MAXSIZE-1)
            printf("error ");
        else
            stack[++top]=item;
    }
    
void out_stack()
    {
        if(top==-1)
            printf("error ");
        else
            printf("%d ",stack[top--]);
    }
    
int main()
{
	int op,num;
	while(1)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&num);
			in_stack(num);
		}			
		else if(op==0)
			out_stack();						
		else if(op==-1)
			return 0;
	}
} 

