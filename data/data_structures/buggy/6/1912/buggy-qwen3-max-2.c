#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char a[105]; // @@ [The stack array 'a' is declared as char, but it should store integers. This causes incorrect storage and output of integer values as characters.]
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
                a[top]=num1;    // @@ [Assigning an int (num1) to a char array element truncates the value to 8 bits, leading to data corruption for values outside 0-255 or -128 to 127.]
    
            }
    
        }
        else//≥ˆ’ª
        {
            if(top==-1)
            {
                printf("error ");
            }
            else
            {    
                printf("%d ",a[top]); // @@ [Printing a char as %d will output its ASCII value, not the original integer that was pushed.]
                top--;
            }
                        
        }
    }
    
    return 0;
}