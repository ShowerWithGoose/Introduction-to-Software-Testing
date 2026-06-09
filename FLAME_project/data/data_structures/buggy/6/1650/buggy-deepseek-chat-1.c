#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX]; // @@ [Error: stack is declared as char type, but the pushed values are integers (e.g., 567). This causes truncation or incorrect storage of integer values, leading to wrong output like "55" instead of "567".]
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
            if(top==100) // @@ [Error: The condition should be top >= MAX-1 or top == MAX-1, since MAX is 100 and array indices go from 0 to 99. top==100 means the stack is already full when top is 99, so this check is off by one and will not correctly detect a full stack.]
            printf("error ");
            else
            {
                stack[++top]=b; // @@ [Error: stack is char type, but b is int. Assigning an int to a char truncates the value, causing data loss. For example, 567 becomes 55 due to truncation to char (mod 256).]
            }
        }
        else if(a==0)
        {
            if(top==-1)
            printf("error ");
            else
            {
                printf("%d ",stack[top]); // @@ [Error: stack[top] is a char, but %d expects an int. This may print incorrect values due to sign extension or truncation, especially for values > 127.]
                top--;    
            }
        }
    scanf("%d",&a);    
    }    
    return 0;
}