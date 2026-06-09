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
               
               push(stack,num); // @@ The push function is called unconditionally even when the stack is full, causing the error message to be printed but the push still occurs, leading to incorrect behavior. The push should only be called when the stack is not full.
        }
        else if (op==0)
        {
            if (top==-1)
            {
                printf("error ");
            }
            int q;
            q=pop(stack); // @@ The pop function is called unconditionally even when the stack is empty, causing the error message to be printed but the pop still occurs, leading to incorrect behavior. The pop should only be called when the stack is not empty.
            printf("%d ",q);
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