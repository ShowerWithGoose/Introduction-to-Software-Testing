#include <stdio.h>
#include <stdlib.h>
int stack[100];
int top = -1;
void push(int s[], int num)
{
    if (top == 99)
    {
        puts("error "); // @@ puts automatically appends a newline character, which violates the output format requiring "error " followed by a space without a newline. Use printf("error "); instead.
    }
    else 
    {
        s[++top] = num;
    }
}
int main()
{
    int x;
    scanf("%d", &x);
    while(x!=-1)
    {
        if(x) 
        {
            int num;
            scanf("%d", &num);
            push(stack, num);
        }
        else 
        {
            if (top == -1)
            {
                puts("error"); // @@ puts appends a newline and lacks the required trailing space specified in the output format. Use printf("error "); instead.
            }
            else 
            {
                printf("%d ", stack[top--]);
            }
        }
        scanf("%d", &x);
    }
    return 0;
}