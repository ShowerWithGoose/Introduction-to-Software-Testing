#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define maxsize 1000

int top=-1;
int stack[maxsize];


int isFull()
{
    return top==maxsize-1;
}

int isEmpty()
{
    return top==-1;
}
int main()
{
    int order,a;
    while(scanf("%d",&order)!=-1)
    {
        if(order==1)
        {
            scanf("%d",&a);

            if(isFull())
            {
                printf("error %d ",a);
            }
            else
            {
            	top++;
                stack[top]=a;
            }
        }
        else if(order==0)
        {
            if(isEmpty())
            {
                printf("error ");
            }
            else
            {
                printf("%d ",stack[top]);
                stack[top]=0;
                top--;
            }
        }
    }

    return 0;
}

