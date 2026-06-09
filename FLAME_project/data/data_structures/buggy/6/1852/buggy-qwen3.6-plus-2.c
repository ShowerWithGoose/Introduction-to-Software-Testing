#include <stdio.h>
#define MAX 100
int stack[MAX];
int front=-1;
void push(int);
void pop();
int main()
{
    int op,data;
    scanf("%d",&op);
    while (op) // @@ The loop condition `while (op)` terminates when op is 0. However, 0 is a valid operation (pop). The loop should continue until -1 is encountered. This causes the program to exit immediately after reading the first '0' operation without processing it or subsequent operations correctly if the sequence starts with 0 or contains 0s as terminators incorrectly. Specifically, for input "1 567 0 -1", it reads 1, pushes 567, then reads 0. The loop `while(0)` terminates, so the pop operation is never executed.
    {

        if (op==0)
        {
            pop();
        }
        if (op==1)
        {
            scanf("%d",&data);
            push(data);
        }
        scanf("%d",&op);
    }
}
void push(int add)
{
    if (front==MAX-1)
    {
        printf("error ");
    }
    else
    {
        front++;
        stack[front]=add;
    }
}
void pop()
{
    if (front==-1)
    {
        printf("error ");
    }
    else
    {
        printf("%d ",stack[front]);
        front--;
    }
}