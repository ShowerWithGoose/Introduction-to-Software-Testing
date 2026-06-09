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
            scanf("%d",&s.data[s.top++]); // @@ [Error: When stack is full, the push value is not read from input, causing subsequent operations to be misaligned. The value should be read even if stack is full (as in the reference program) to maintain input synchronization.]
        }
        else if(0==op)
        {
            if(s.top==0)
            printf("error ");
            else
            printf("%d",s.data[--s.top]); // @@ [Error: Missing space after the popped integer. The output format requires a space after each popped element. Should be printf("%d ", ...).]
        }
    }
    return 0;
}