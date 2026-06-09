#include <stdio.h>
#include <stdlib.h>
int stack[100];
int top = -1;
void push(int s[], int num)
{
    if (top == 99)
    {
        puts("error "); // @@ This uses puts which adds a newline, but the expected output should not have a newline here. Also, the error message should be "error " (with a space) but puts adds a newline, causing the output to be on a separate line.
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
                puts("error"); // @@ This uses puts which adds a newline, but the expected output should not have a newline here. Also, the error message should be "error " (with a space) but puts adds a newline, causing the output to be on a separate line.
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