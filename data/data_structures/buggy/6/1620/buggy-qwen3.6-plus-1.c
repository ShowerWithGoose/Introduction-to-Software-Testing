#include <stdio.h>
#include <stdlib.h>
int stack[100];
int top = -1;
void push(int s[], int num)
{
    if (top == 99)
    {
        puts("error "); // @@ puts automatically appends a newline character, violating the requirement to output everything on a single line; should use printf("error ");
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
                puts("error"); // @@ puts automatically appends a newline and misses the required trailing space; should use printf("error ");
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