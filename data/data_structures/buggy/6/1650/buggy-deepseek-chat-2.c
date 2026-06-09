#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX]; // @@ [Error: stack is declared as char array, but it stores integers. Should be int stack[MAX];]
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
            if(top==100) // @@ [Error: Should check top == MAX-1 (i.e., 99) for full stack, not top == 100. Also, MAX is 100, so valid indices are 0-99.]
            printf("error ");
            else
            {
                stack[++top]=b; // @@ [Error: stack is char array, cannot store integer b properly. Also, if top becomes 100, this writes out of bounds.]
            }
        }
        else if(a==0)
        {
            if(top==-1)
            printf("error ");
            else
            {
                printf("%d ",stack[top]); // @@ [Error: stack[top] is char, but %d expects int, causing incorrect output.]
                top--;    
            }
        }
    scanf("%d",&a);    
    }    
    return 0;
}