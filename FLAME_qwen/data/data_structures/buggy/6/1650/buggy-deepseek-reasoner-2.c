#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX]; // @@ Error: stack should be declared as int, not char, because it stores integer values.
int top=-1;
int main()
{
    int a,b;
    scanf("%d",&a);
    while(a!=-1)
    {
        if(a==1)
        {
            scanf("%d",&b); // @@ Error: According to the reference, the integer should only be read when the stack is not full, to maintain input synchronization.
            if(top==100) // @@ Error: Full condition should check top == MAX-1 (99), not top == 100, because maximum index is 99.
            printf("error ");
            else
            {
                stack[++top]=b; // @@ Error: stack is char, cannot store integer values correctly; also, this line is reached even if stack is full due to incorrect condition.
            }
        }
        else if(a==0)
        {
            if(top==-1)
            printf("error ");
            else
            {
                printf("%d ",stack[top]); // @@ Error: stack[top] is char, but printing with %d is incorrect for char; also, stack should be int.
                top--;    
            }
        }
    scanf("%d",&a);    
    }    
    return 0;
}