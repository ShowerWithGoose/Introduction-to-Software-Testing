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
               
               push(stack,num); // @@ [Push is executed even when the stack is full, causing buffer overflow. The push() call should be inside an else block.]
        }
        else if (op==0)
        {
            if (top==-1)
            {
                printf("error ");
            }
            int q;
            q=pop(stack); // @@ [Pop is executed even when the stack is empty, leading to undefined behavior (accessing invalid memory). The pop() and printf should only occur if the stack is not empty.]
            printf("%d ",q); // @@ [This prints a garbage value when the stack is empty because pop() still returns an invalid value.]
        }  
        }
    }
    
    
    return 0;
}

void push(int *stack,int a)
{
    stack[++top]=a; // @@ [No check for stack full condition here; relies on caller, but caller already printed "error" and still calls push, leading to overflow.]
    
}
int pop(int *stack)
{
    
    
        int a=stack[top]; // @@ [No check for empty stack; if called when empty, accesses invalid memory (stack[-1]).]
        top--;
        return a;
    
}