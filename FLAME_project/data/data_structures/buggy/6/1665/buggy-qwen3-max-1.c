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
} // @@ [When the stack is empty, the function prints "error " but still returns an undefined value (implicitly 0 due to missing return in some paths), which the caller then prints as "%d ", causing an extra incorrect number like "6" in the output.]

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
            printf("%d ",Stack_Pop(stack)); // @@ [This line always prints the return value of Stack_Pop as an integer followed by a space, even when the stack is empty. In the empty case, Stack_Pop prints "error " but also returns an indeterminate value (likely 0 or garbage), which gets printed as a number (e.g., "6"), leading to wrong output.]
        }
    }
}