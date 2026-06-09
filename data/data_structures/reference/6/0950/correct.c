#include<stdio.h>
int main()
{
    int stack[100];
    int top = -1;
    int input, temp;
    while(scanf("%d", &input) != EOF && input != -1)
    {
        if(input == 1)
        {
            scanf("%d", &temp);
            if(top == 99)
                printf("error ");
            else
                stack[++top] = temp;
        }
        else
        {
            if(top == -1)
                printf("error ");
            else
                printf("%d ", stack[top--]);
        }
    }
    return 0;
}
