#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack
{
    int top;
    int data[100];
}stack;
int main()
{
    stack s;
    s.top=0;
    int op;
    while (scanf("%d",&op)!=EOF)
    {
        if(-1==op)
        break;
        else if(1==op)
        {
            if(s.top==100)
            printf("error ");
            else
            scanf("%d",&s.data[s.top++]);
        }
        else if(0==op)
        {
            if(s.top==0)
            printf("error ");
            else
            printf("%d ",s.data[--s.top]); // @@ [Missing space after popped value; output format requires a space after each element including the last one]
        }
    }
    return 0;
}