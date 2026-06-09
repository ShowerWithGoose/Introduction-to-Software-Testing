#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX]; // @@ [Error: stack should be of type int to store integer values correctly; using char truncates values to 0-255, causing wrong output for numbers like 567.]
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
            if(top==100) // @@ [Error: condition should check if top == MAX-1 (i.e., 99) because stack indices are 0 to 99; current check never detects full stack.]
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