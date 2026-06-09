#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char a[105]; // @@ [The stack array 'a' is declared as char, but it should be int to store integer values pushed onto the stack. Using char causes incorrect storage and output of integers.]
#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))
int main()
{
    int i=0,num,num1;
    int top=-1;
    while(1)
    {
        scanf("%d",&num);
        if(num==-1)
            break;
        else if(num==1)//»Î’ª
        {
            scanf("%d",&num1);
            if(top==100)
            {
                printf("error ");
            }
            else
            {
                top++;
                a[top]=num1;    // @@ [Assigning an int value 'num1' to a char array 'a' truncates the value to 8 bits, leading to incorrect data storage and output.]
    
        }
        else//≥ˆ’ª
        {
            if(top==-1)
            {
                printf("error ");
            }
            else
            {    
                printf("%d ",a[top]); // @@ [Printing a char as %d will output its ASCII value or truncated integer, not the original pushed integer.]
                top--;
            }
                        
        }
    }
    
    return 0;
}