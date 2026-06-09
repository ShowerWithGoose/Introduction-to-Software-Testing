#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include <ctype.h>
#define MAXSIZE 100
int stack[MAXSIZE]={0},top=-1;

int isEmpty();
int isFull();
void push(int s[],int item);
int pop(int s[]);
int main()
{
    int num,item,ans;
    while(scanf("%d",&num)!=EOF)
    {
        if(num==1)
        {
            scanf("%d",&item);
            push(stack,item);
        }
        else if(num==0)
        {
            ans=pop(stack);
            if(ans)
            {
                printf("%d ",ans);
            }
        }
        else if(num==-1)
        {
            break;
        }
    }
    return 0;
}
int isEmpty()
{
    return top==-1;
}
int isFull()
{
    return top==MAXSIZE-1;
}
void push(int s[],int item)
{
    if(isFull())
        printf("error ");
    else
        s[++top]=item;
}
int pop(int s[])
{
    if(isEmpty())
    {
        printf("error ");
        return 0;
    }

    else
        return s[top--];
}



