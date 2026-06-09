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
        printf("error "); // @@ The function prints "error " but does not return a value, causing undefined behavior. The garbage value returned is then printed by main() as an extra number.
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
            printf("%d ",Stack_Pop(stack));
        }
    }
}