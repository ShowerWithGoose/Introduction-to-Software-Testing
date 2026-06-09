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
                a[top]=num1;    // @@ [Assigning an integer 'num1' to a char array 'a' truncates the value to a single byte, leading to data corruption for values outside the char range.]
    
        }
        else//≥ˆ’ª
        {
            if(top==-1)
            {
                printf("error ");
            }
            else
            {    
                printf("%d ",a[top]); // @@ [Printing a char value with %d may produce unexpected results because the stored value was truncated during assignment.]
                top--;
            }
                        
        }
    }
    
    return 0;
}