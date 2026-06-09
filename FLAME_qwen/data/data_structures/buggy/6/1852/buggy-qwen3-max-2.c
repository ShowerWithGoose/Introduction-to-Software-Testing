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
    while (op) // @@ [The loop condition should continue until op == -1, but this loop stops when op is 0 or -1. Since the problem states that -1 ends the operations, the condition should be 'while (op != -1)'. As written, when op is -1, the loop exits correctly, but when op is 0 (a valid operation), the loop body runs, then reads next op; however, if the first input is -1, the loop doesn't run — which is correct. But the real issue is that after processing a 0 or 1, it reads next op, and if that op is -1, loop exits. However, the bug is that when op is -1, the loop condition 'while(op)' treats -1 as true (non-zero), so it enters the loop incorrectly. Thus, the condition must be 'while (op != -1)'.]
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