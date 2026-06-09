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
    while (op) // @@ [The loop condition should continue until op == -1, but it stops when op is 0 or -1. Since the problem states that -1 ends the operations, the condition should be 'while (op != -1)'. As written, the loop exits on op=0 (a valid operation) and never processes the terminating -1 correctly.]
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