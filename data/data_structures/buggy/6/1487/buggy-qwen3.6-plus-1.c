#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define MAXSIZE 1024 // @@ The problem specifies a maximum stack capacity of 100, so MAXSIZE should be 100.

int stack[MAXSIZE];
int top=-1;//≥ı ºªØ 

void push(int stack[], int item)
{
    if(top==MAXSIZE-1)
    {
        printf("error"); // @@ The problem requires outputting "error " followed by a space, so it should be printf("error ");.
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
        printf("error"); // @@ The problem requires outputting "error " followed by a space, so it should be printf("error ");.
    }
    else
    {
        printf("%d", stack[top]); // @@ The problem requires a space after each popped element, so it should be printf("%d ", stack[top]);.
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