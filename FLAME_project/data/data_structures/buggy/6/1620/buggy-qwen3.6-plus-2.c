#include <stdio.h>
#include <stdlib.h>
int stack[100];
int top = -1;
void push(int s[], int num)
{
    if (top == 99)
    {
        printf("error "); // @@ The original code used puts("error "), which appends a newline. The problem requires output on a single line separated by spaces. Also, the reference implementation uses printf with a space.
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
                printf("error "); // @@ The original code used puts("error"), which appends a newline and lacks the trailing space required by the output format. It should be printf("error ") to match the expected output format.
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