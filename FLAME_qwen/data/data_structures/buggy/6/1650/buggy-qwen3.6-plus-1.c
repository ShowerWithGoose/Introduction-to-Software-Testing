#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX]; // @@ [Error: The stack should store integers as per the problem description, so the array type should be int instead of char.]
int top=-1;
int main()
{
    int a,b;
    scanf("%d",&a);
    while(a!=-1)
    {
        if(a==1)
        {
            scanf("%d",&b);
            if(top==100) // @@ [Error: The stack capacity is 100 and top starts at -1, so the stack is full when top == 99 (MAX-1). Checking top==100 allows an out-of-bounds write.]
            printf("error ");
            else
            {
                stack[++top]=b;
            }
        }
        else if(a==0)
        {
            if(top==-1)
            printf("error ");
            else
            {
                printf("%d ",stack[top]);
                top--;    
            }
        }
    scanf("%d",&a);    
    }    
    return 0;
}