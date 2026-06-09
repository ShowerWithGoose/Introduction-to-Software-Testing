#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int stack[100];
int top;
void initstack()
{
    top = -1;
}
int isempty()
{
    return top == -1;
}
int isfull()
{
    return top == 99;
}
void Error(char s[])
{
    printf("%s",s);
    exit(-1);
}
void push(int s[],int i)//入栈
{
    if(isfull())
        Error("error ");
    else
        s[++top] = i;
}
int pop(int s[])//出栈
{
        return s[top--];
}
int main()
{
    int n,t;
    initstack();
    while (scanf("%d", &n))
    {
        if(n==-1)
            break;
        else if (n == 1)
        {
            scanf("%d", &t);
            push(stack, t);
        }
        else
        {
            if(top!=-1)
            printf("%d ", pop(stack));
            else
                printf("error ");
        }
    }
    return 0;
}

