//
//  main.c
//  栈
//
//  Created by  on 2022/4/14.
//

#include <stdio.h>
#define MAXSIZE 100
typedef int ELEMTYPE;
ELEMTYPE stack[MAXSIZE];
int top;
ELEMTYPE n;
void init_stack(void);
int isFull(void);
int isEmpty(void);
void error(char s[]);
void push(ELEMTYPE stack[], ELEMTYPE item);
ELEMTYPE pop(ELEMTYPE stack[],ELEMTYPE n);
int main(int argc, const char * argv[])
{
    int action;
    int item = 0;
    init_stack();
    scanf("%d",&action);
    while (1)
    {
        if (!action)
            pop(stack,n);
        if (action)
        {
            scanf("%d",&item);
            push(stack, item);
        }
        if (action==-1)
            break;
        scanf("%d",&action);
    }
    return 0;
}
void init_stack(void)
{
    top=-1;
}
int isFull(void)
{
    return top==MAXSIZE-1;
}
int isEmpty(void)
{
    return top==-1;
}
void push(ELEMTYPE stack[], ELEMTYPE item)
{
    if (isFull())
        printf("error ");
    else
        stack[++top] = item;
}
void error(char s[])
{
    printf("%s\n",s);
    return;
}
ELEMTYPE pop(ELEMTYPE stack[],ELEMTYPE n)
{
    if (isEmpty())
        printf("error ");
    else
    {
        n=stack[top];
        printf("%d ",n);
        return stack[top--];
    }
    return 0;
}

