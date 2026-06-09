#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX]; // @@ [The stack is declared as char array, but it should store integers. This causes incorrect storage and output of integer values.]
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
            if(top==100) // @@ [The condition should be top == MAX - 1 or top == 99, since the stack indices go from 0 to 99 for size 100. Checking top == 100 allows pushing beyond capacity.]
            printf("error ");
            else
            {
                stack[++top]=b; // @@ [Storing an int into a char array truncates the value to 8 bits, leading to data corruption for values outside char range.]
            }
        }
        else if(a==0)
        {
            if(top==-1)
            printf("error ");
            else
            {
                printf("%d ",stack[top]); // @@ [Reading a char as %d leads to sign extension or garbage output because stack[top] is a char, not an int.]
                top--;    
            }
        }
    scanf("%d",&a);    
    }    
    return 0;
}