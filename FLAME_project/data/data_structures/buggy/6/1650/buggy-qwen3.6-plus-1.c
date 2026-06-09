#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX]; // @@ The stack data type is 'char', which cannot hold large integers like 567 correctly (overflow/truncation). It should be 'int'.
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
            if(top==100) // @@ The condition checks for full stack incorrectly. Since top is 0-indexed and MAX is 100, valid indices are 0-99. Full is top == 99 or top == MAX - 1. Also, it doesn't prevent the push logic below if error is printed, though here it's in else. But the boundary check value is wrong relative to array size if we consider 0-99. Actually, if top reaches 99, next push makes it 100 which is out of bounds. So check should be top >= MAX - 1 before incrementing. Here it checks top==100 which is already out of bounds or unreachable if checked before increment. Correct check for "is full" before pushing is top == MAX - 1.
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