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
               
               push(stack,num); // @@ [Push is executed even when the stack is full, leading to buffer overflow. The function call should be inside an else block.]
        }
        else if (op==0)
        {
            if (top==-1)
            {
                printf("error ");
            }
            int q;
            q=pop(stack); // @@ [Pop is executed even when the stack is empty, which leads to undefined behavior (accessing invalid memory). The pop and print should only occur if the stack is not empty.]
            printf("%d ",q); // @@ [This prints the return value of pop even when the stack was empty, which may print garbage or cause runtime errors.]
        }  
        }
    }
    
    
    return 0;
}

void push(int *stack,int a)
{
    stack[++top]=a; // @@ [No check for stack full condition inside push; relies on caller, but caller already printed "error" and still calls push, causing overflow.]
    
}
int pop(int *stack)
{
    
    
        int a=stack[top]; // @@ [No check for empty stack inside pop; if called when empty, accesses invalid index (top = -1), leading to undefined behavior.]
        top--;
        return a;
    
}