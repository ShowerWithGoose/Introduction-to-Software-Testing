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
    while (op) // @@ [Loop condition should be while(op != -1) because 0 is a valid pop operation, and -1 ends operations. Current condition exits when op becomes 0, missing pop operations.]
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