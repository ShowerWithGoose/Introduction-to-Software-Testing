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
        printf("error "); // @@ [Missing space after "error" in pop case, but here also needs space to match expected output format; however, main issue is inconsistent spacing and missing space after error in both functions]
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
        printf("error "); // @@ [Original code printed "error" without trailing space; problem requires a space after every output element including "error"]
    }
    else
    {
        printf("%d ", stack[top]); // @@ [Missing space after popped number; problem requires space after every output element]
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