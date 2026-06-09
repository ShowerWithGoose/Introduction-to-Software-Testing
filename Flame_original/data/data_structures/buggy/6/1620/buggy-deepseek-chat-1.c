#include <stdio.h>
#include <stdlib.h>
int stack[100];
int top = -1;
void push(int s[], int num)
{
    if (top == 99)
    {
        puts("error "); // @@ The output should be "error " followed by a space, but puts adds a newline, which does not match the expected output format. Also, the program should continue after an error, but this does not handle the case where a push is attempted when the stack is full; the reference program does not check for stack full errors, but the problem description says to output "error" if push is attempted when full. However, the reference program does not implement this check, so this check is an error in logic relative to the reference. Additionally, the output should be "error " (with a space) without a newline, so using printf("error ") is correct.
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
                puts("error"); // @@ The output should be "error " (with a space) and no newline, but puts adds a newline. The reference program uses printf("error ") without a newline. Also, the problem expects a space after "error", so this should be printf("error ").
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