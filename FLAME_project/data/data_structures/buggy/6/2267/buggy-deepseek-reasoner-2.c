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
               
               push(stack,num); // @@ push should be skipped when stack is full
        }
        else if (op==0)
        {
            if (top==-1)
            {
                printf("error ");
            }
            int q;
            q=pop(stack); // @@ pop should be skipped when stack is empty
            printf("%d ",q); // @@ printf should be skipped when stack is empty
        }  
        }
    }
    
    
    return 0;
}

void push(int *stack,int a)
{
    stack[++top]=a; // @@ stack overflow if top==Maxsize-1
    
}
int pop(int *stack)
{
    
    
        int a=stack[top]; // @@ accessing stack[top] with top=-1 is invalid
        top--; // @@ decrementing top when top=-1 is invalid
        return a;
    
}