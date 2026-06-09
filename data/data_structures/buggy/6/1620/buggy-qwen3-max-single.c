#include <stdio.h>
#include <stdlib.h>
int stack[100];
int top = -1;
void push(int s[], int num)
{
    if (top == 99)
    {
        puts("error "); // @@ [Using puts() adds a newline, but expected output requires only "error " followed by a space and no newline. Also, the problem expects all output on a single line.]
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
                puts("error"); // @@ [Using puts() outputs "error\n", but expected output is "error " (with a space and no newline). This breaks the required output format.]
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