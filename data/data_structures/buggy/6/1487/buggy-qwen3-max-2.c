#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define MAXSIZE 1024

int stack[MAXSIZE];
int top=-1;//≥ı ºªØ 

void push(int stack[], int item)
{
    if(top==MAXSIZE-1)
    {
        printf("error "); // @@ [The problem requires a space after "error", but original code prints "error" without space. Also, it should continue processing instead of just printing once; however, the main issue here is missing space and not exiting, but the bigger error is in pop formatting and missing spaces in output]
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
        printf("error "); // @@ [The problem requires a space after "error", but original code prints "error" without space. This line should print "error " with a trailing space to match expected output format]
    }
    else
    {
        printf("%d ", stack[top]); // @@ [Missing space after popped value; problem requires each output element followed by a space, including the last one. Original prints "%d" without trailing space]
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