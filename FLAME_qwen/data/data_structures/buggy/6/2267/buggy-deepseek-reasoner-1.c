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
                if (top==Maxsize-1) // @@ [Error: prints error but does not prevent subsequent push; should skip push if full]
                {
                     printf("error ");
                }
               
               push(stack,num); // @@ [Error: push is executed even when stack is full, causing overflow]
        }
        else if (op==0)
        {
            if (top==-1) // @@ [Error: prints error but continues to perform pop; should skip pop if empty]
            {
                printf("error ");
            }
            int q;
            q=pop(stack); // @@ [Error: pop is called even when stack is empty, leading to out-of-bounds access]
            printf("%d ",q);
        }  
        }
    }
    
    
    return 0;
}

void push(int *stack,int a)
{
    stack[++top]=a; // @@ [Error: no check for full stack; if called when full, causes buffer overflow]
    
}
int pop(int *stack)
{
    
    
        int a=stack[top]; // @@ [Error: if stack is empty (top == -1), accessing stack[-1] is out-of-bounds]
        top--;
        return a;
    
}