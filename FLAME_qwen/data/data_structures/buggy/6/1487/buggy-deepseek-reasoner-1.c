#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define MAXSIZE 1024 // @@ should be 100 to match problem's maximum capacity
int stack[MAXSIZE];
int top=-1;//≥ı ºªØ 

void push(int stack[], int item)
{
    if(top==MAXSIZE-1)
    {
        printf("error"); // @@ should print "error " (with a trailing space) per problem requirement
    }
    else
    {
        top++;
        stack[top]=item;
    }
}

void pop(int stack[])
{
    if(top==-1)
    {
        printf("error"); // @@ should print "error " (with a trailing space) per problem requirement
    }
    else
    {
        printf("%d", stack[top]); // @@ should print with a space after the number, e.g., "%d "
        top--;
    }
}

int main(int argc, const char * argv[])
{
    int action, item;
    
    while(1)
    {
        scanf("%d", &action);
        if(action==1)//push
        {
            scanf("%d", &item);
            push(stack, item);
        }
        else if(action==0)//pop
        {
            pop(stack);
        }
        else if(action==-1)
        {
            break;
        }
    }
    
    return 0;
}