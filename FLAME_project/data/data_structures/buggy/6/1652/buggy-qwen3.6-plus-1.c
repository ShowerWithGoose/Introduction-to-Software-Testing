#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    int stack[100] = { 0 };
    int top = -1;
    int option;
    do
    {
        scanf("%d", &option);
        if (option == -1)
            break;
        else if (option == 1)//执行入栈操作
        {
            int newnum;
            scanf("%d", &newnum);
            if (top == 99)
                printf("error ");
            else
                stack[++top] = newnum;
        }
        else if (option == 0)//执行出栈操作
        {
            if (top == -1)
                printf("error ");
            else
                printf("%d ", stack[top]); // @@ The code prints the top element but fails to decrement 'top', meaning the element is not actually popped from the stack. Subsequent pop operations will repeatedly print the same value. It should be 'printf("%d ", stack[top--]);'.
        }
    } while (option != -1);
    return 0;
}