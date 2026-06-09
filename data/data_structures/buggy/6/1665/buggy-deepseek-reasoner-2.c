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

int Stack_Pop(int s[]) // @@ [Function declared to return int but missing return statement when stack is empty; causes undefined behavior and potential compilation error.]
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
            printf("%d ",Stack_Pop(stack)); // @@ [Unconditionally prints the return value of Stack_Pop, but when stack is empty, Stack_Pop prints "error " and returns no valid value, resulting in extra garbage output.]
        }
    }
}