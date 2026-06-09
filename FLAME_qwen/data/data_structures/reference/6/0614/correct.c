#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define len 100
int stack[len];
int top = -1;
int push(int x)
{
    if(top == len-1)
    {
        printf("error ");
        return -1;
    }
    stack[++top] = x;
    return 1;
}
int pop()
{
    if(top == -1)
    {
        printf("error ");
        return -1;
    }
    top--;
    return 1;
}
int main()
{
	int op,num;
    scanf("%d",&op);
    while(op != -1)
    {
        if(op == 1)
        {
            scanf("%d",&num);
            push(num);
        }
        else if(op == 0)
        {
            int flag = pop();
            if(flag == 1)
            {num = stack[top+1];
            printf("%d ",num);}
        }
        scanf("%d",&op);
    }
	return 0;
} 
