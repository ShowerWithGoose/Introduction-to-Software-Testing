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
               
               push(stack,num); @@ // Error: Push is executed even when stack is full. Should only push if not full.
        }
        else if (op==0)
        {
            if (top==-1)
            {
                printf("error ");
            }
            int q;
            q=pop(stack); @@ // Error: Pop is called even when stack is empty, leading to undefined behavior.
            printf("%d ",q); @@ // Error: Prints popped value even after "error" was printed for empty stack.
        }  
        }
    }
    
    
    return 0;
}

void push(int *stack,int a)
{
    stack[++top]=a; @@ // Error: No check for stack overflow inside push; relies on external check which is flawed.
    
}
int pop(int *stack)
{
    
    
        int a=stack[top];
        top--;
        return a; @@ // Error: No check for stack underflow inside pop; may access invalid memory when stack is empty.
    
}