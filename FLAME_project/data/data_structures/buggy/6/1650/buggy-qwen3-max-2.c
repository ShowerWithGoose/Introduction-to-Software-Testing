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
            if(top==100) // @@ [The condition should be top == MAX - 1 or top == 99 because the stack size is MAX=100 and indices go from 0 to 99. Checking top==100 means one extra push beyond capacity is allowed.]
            printf("error ");
            else
            {
                stack[++top]=b; // @@ [Assigning an int to a char array truncates the value to 8 bits, so 567 becomes 567 % 256 = 55, which explains the buggy output "55".]
            }
        }
        else if(a==0)
        {
            if(top==-1)
            printf("error ");
            else
            {
                printf("%d ",stack[top]); // @@ [Reading from a char array returns a truncated (8-bit) value, so 567 stored earlier is read as 55.]
                top--;    
            }
        }
    scanf("%d",&a);    
    }    
    return 0;
}