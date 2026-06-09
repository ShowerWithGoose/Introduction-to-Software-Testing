#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

int top = 0;
int stack[105] = {};


int pop();
void push(int);
int main()
{
    #ifdef ACU
    freopen("input.txt","r",stdin);
    #endif

    int op = 0,data = 0;
    while (scanf("%d",&op),op != -1)
    {
        if (op == 1)
        {
            scanf("%d",&data);
            if (top == max+1)
            {
                printf("error ");
            }
            else
            {
                push(data);
            }
            
        }
        else
        {
            if (top == 0)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",pop());
            }
        }
    }
    

    return 0;
}


int pop()
{
    int temp = 0;
    temp = stack[--top],stack[top] = 0;
    return temp;
}


void push(int data)
{
    stack[top++] = data;
}
