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
        printf("error "); // @@ [Missing space after "error" in pop case, but here also needs space to match expected output format; however, main issue is missing space in pop. But this line also outputs "error" without trailing space as required]
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
        printf("error "); // @@ [This is correct: outputs "error " with space. However, the push function above prints "error" without space — inconsistency leads to formatting error. But primary bug is in push not printing space. Also, both should print "error " with space.]
    }
    else
    {
        printf("%d ", stack[top]); // @@ [Missing space after %d in output; problem requires each popped element followed by a space, including last one. This prints number but no trailing space. Should be "%d "]
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