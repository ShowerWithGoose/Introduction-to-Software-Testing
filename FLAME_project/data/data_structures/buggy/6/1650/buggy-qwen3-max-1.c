#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX]; // @@ [The stack is declared as char array, but it should store integers. This causes incorrect storage and retrieval of integer values like 567, leading to wrong output.]
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
            if(top==100) // @@ [The condition should be top == MAX - 1 or top == 99 because the stack size is MAX=100 and top starts at -1. Checking top==100 means one extra push beyond capacity is allowed, which is incorrect. However, in this specific test case, this error does not trigger because only one push occurs. The primary error is the char stack type.]
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