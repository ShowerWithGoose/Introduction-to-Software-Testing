#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char a[105]; // @@ [The stack array 'a' is of type char, but it should store integers. This causes incorrect storage and output of integer values.]
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
                a[top]=num1;    // @@ [Assigning an int value to a char array truncates the value to 8 bits, leading to data loss and incorrect pop outputs.]
    
        }
        else//≥ˆ’ª
        {
            if(top==-1)
            {
                printf("error ");
            }
            else
            {    
                printf("%d ",a[top]); // @@ [Printing a char as %d will sign-extend or misinterpret the stored byte, producing wrong integer output.]
                top--;
            }
                        
        }
    }
    
    return 0;
}