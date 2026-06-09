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
               
               push(stack,num); @@ [The push operation is executed even when the stack is full, leading to buffer overflow. The code prints "error " but still calls push(), which writes beyond the array bounds.]
        }
        else if (op==0)
        {
            if (top==-1)
            {
                printf("error ");
            }
            int q;
            q=pop(stack); @@ [The pop operation is executed even when the stack is empty. Although "error " is printed, the code still calls pop(), which accesses stack[-1], causing undefined behavior.]
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