#include <stdio.h>
#include <stdlib.h>
int stack[200], top = -1;
void push_stack(int num)
{
    if(top == 99)
    {
        printf("error ");
        return ;
    }
    top++;
    stack[top] = num;
}
int pop_stack()
{
    if(top == -1)
    {
        printf("error ");
        return EOF;
    }
    int temp = stack[top];
    top--;
    return temp;
}
int main()
{
    int flag;
    while (scanf("%d", &flag) != -1)
    {
        if (flag == 1)
        {
            int num;
            scanf("%d", &num);
            push_stack(num);
        }
        else if (flag == 0)
        {
            int temp = pop_stack();
            if(temp != EOF)
            printf("%d ", temp);
        }
    }
    return 0;
}
