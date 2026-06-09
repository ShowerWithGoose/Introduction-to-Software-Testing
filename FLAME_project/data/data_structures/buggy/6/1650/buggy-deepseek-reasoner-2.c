#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX]; // @@ [Stack should be of type int to store integer values; using char truncates values to 8 bits, causing incorrect output like 55 instead of 567]
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
            if(top==100) // @@ [Overflow check condition is incorrect; when stack has 100 elements, top index is 99, not 100. Should be if(top==MAX-1) to check full stack]
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