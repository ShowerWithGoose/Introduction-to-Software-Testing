#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX]; // @@ [The stack should store integers, not characters. Using char will cause data truncation and incorrect output when printed with %d.]
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
            if(top==100) // @@ [The stack capacity is 100, so valid indices are 0 to 99. The stack is full when top is 99 (MAX-1). Checking top==100 allows an out-of-bounds write.]
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