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
                printf("%d ", stack[top]); // @@ [The element is printed but not removed from the stack; 'top' should be decremented after printing to simulate a real pop operation.]
        }
    } while (option != -1);
    return 0;
}