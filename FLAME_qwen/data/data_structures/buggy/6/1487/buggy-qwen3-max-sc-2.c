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
        printf("error "); // @@ [The problem requires outputting "error " (with a space) for both push and pop errors, but original code outputs "error" without space. Also, after printing error, the program should continue processing, not exit, which is correct here, but missing space causes mismatch with expected output format.]
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
        printf("error "); // @@ [Same issue: missing space after "error". Expected output format requires a space after each popped element or error message.]
    }
    else
    {
        printf("%d ", stack[top]); // @@ [Missing space after the printed number. The problem specifies that output elements must be separated by spaces and there must be a space after the last element.]
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