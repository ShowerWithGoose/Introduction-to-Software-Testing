#include <stdio.h>
#include <stdlib.h>
int stack[100];
int top = -1;
void push(int s[], int num)
{
    if (top == 99)
    {
        puts("error "); // @@ The reference program prints "error " (with a space) using printf, but this uses puts which adds a newline and does not match the expected output format. Also, the reference program does not stop on error; it continues. However, the main issue is the output format: the reference prints "error " without a newline, while puts adds a newline.
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
                puts("error"); // @@ The reference program prints "error " (with a space) using printf, but this uses puts which adds a newline and does not include a trailing space. The expected output format requires a space after "error".
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