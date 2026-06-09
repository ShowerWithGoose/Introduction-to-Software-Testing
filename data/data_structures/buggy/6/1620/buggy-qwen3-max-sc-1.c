#include <stdio.h>
#include <stdlib.h>
int stack[100];
int top = -1;
void push(int s[], int num)
{
    if (top == 99)
    {
        puts("error "); // @@ [puts appends a newline, but expected output requires only "error " followed by space and no newline; also inconsistent with pop error handling which uses puts("error") without trailing space]
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
                puts("error"); // @@ [uses puts which adds a newline; should use printf("error ") to match expected output format with trailing space and no newline]
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