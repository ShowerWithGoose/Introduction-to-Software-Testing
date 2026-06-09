#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
int isfull(int stack[]);
int isempty(int stack[]);
int top=-1;
int main()
{
    int stack[MAXSIZE];
    int op,num;
    do{
        scanf("%d",&op);
        if(op==1)
        {
            if(isfull(stack)==1)
            {
                printf("error ");
            }
            else
            {
                scanf("%d ",&stack[++top]);
            }
            
        }
        else if(op==0)
        {
            if(isempty(stack)==1)
            {
                printf("error ");
            }
            else
            printf("%d ",stack[top--]);
        }
    }while(op!=-1);
    return 0;
}
int isfull(int stack[])
{
    return top==MAXSIZE-1;
}
int isempty(int stack[])
{
    return top==-1;
}
