#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX]; // @@ [The stack is declared as char array, but it should store integers. This causes incorrect storage and retrieval of integer values.]
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
            if(top==100) // @@ [The condition should be top == MAX - 1 or top == 99, since top is zero-based and MAX is 100. Checking top == 100 allows pushing beyond the array bounds.]
            printf("error ");
            else
            {
                stack[++top]=b; // @@ [Assigning an int 'b' to a char array element truncates the value, leading to data corruption.]
            }
        }
        else if(a==0)
        {
            if(top==-1)
            printf("error ");
            else
            {
                printf("%d ",stack[top]); // @@ [Printing a char as %d will output its ASCII value, not the original integer that was (truncatedly) stored.]
                top--;    
            }
        }
    scanf("%d",&a);    
    }    
    return 0;
}