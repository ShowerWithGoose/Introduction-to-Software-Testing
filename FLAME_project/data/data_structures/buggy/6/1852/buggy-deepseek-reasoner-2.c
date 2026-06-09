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
    while (op)  // @@ [The loop condition should be `while (op != -1)` because the end-of-operations marker is -1, not 0. Here, when op is 0 (a valid pop operation), the loop immediately exits, so pop operations are never processed. For the test case input "1 567 0 -1", the program reads 1, processes push, then reads 0, but the while condition (0) is false, so it exits without performing the pop. Hence no output is produced.]
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