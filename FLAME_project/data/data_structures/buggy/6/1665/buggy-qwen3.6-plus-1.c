#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define MAXSIZE 100

int top;

void Init_Stack()
{
    top=-1;
}

int Stack_Empty()
{
    return top==-1;
}

int Stack_Full()
{
      return top==MAXSIZE-1;
}

void Stack_Push(int s[],int a)
{
    if(Stack_Full())
    {
        printf("error ");
    }
    else
    {
        s[++top]=a;
    }
}

int Stack_Pop(int s[])
{
    if(Stack_Empty())
    {
        printf("error ");
    }
    else
    {
        return s[top--];
    }
}

int main()
{
    int operation,temp,stack[MAXSIZE]={0};
    
    Init_Stack();
    
    while(1)
    {
        scanf("%d",&operation);
        
        if(operation==-1)
        {
            return 0;
        }
        else if(operation==1)
        {
            scanf("%d",&temp);
            
            Stack_Push(stack,temp);
        }
        else if(operation==0)
        {
            if (Stack_Empty()) { // @@ The original code prints the return value of Stack_Pop even when the stack is empty. Stack_Pop prints "error " but returns an undefined/old value (0 in this case due to initialization or garbage), which gets printed. We need to handle the error case here to avoid printing the invalid return value.
                Stack_Pop(stack);
            } else {
                printf("%d ",Stack_Pop(stack));
            }
        }
    }
}