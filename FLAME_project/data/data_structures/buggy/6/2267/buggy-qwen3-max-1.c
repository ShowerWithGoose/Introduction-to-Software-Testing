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
               
               push(stack,num); // @@ [The push operation is executed even when the stack is full, leading to buffer overflow and incorrect behavior. The push() call should be inside an else block.]
        }
        else if (op==0)
        {
            if (top==-1)
            {
                printf("error ");
            }
            int q;
            q=pop(stack); // @@ [The pop operation is executed even when the stack is empty, which leads to accessing invalid memory (stack[-1]) and printing garbage or undefined values. The pop() call and printf should only happen if the stack is not empty.]
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