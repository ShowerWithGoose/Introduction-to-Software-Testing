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
               
               push(stack,num); // @@ [Push is executed even when stack is full, causing buffer overflow]
        }
        else if (op==0)
        {
            if (top==-1)
            {
                printf("error ");
            }
            int q;
            q=pop(stack); // @@ [Pop is executed even when stack is empty, leading to undefined behavior]
            printf("%d ",q); // @@ [Prints garbage or causes crash when pop was on empty stack]
        }  
        }
    }
    
    
    return 0;
}

void push(int *stack,int a)
{
    stack[++top]=a; // @@ [No check for stack full condition inside push function]
    
}
int pop(int *stack)
{
    
    
        int a=stack[top]; // @@ [Accesses stack[top] even when top is -1 (empty stack)]
        top--;
        return a;
    
}