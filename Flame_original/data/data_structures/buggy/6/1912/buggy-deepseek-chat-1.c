#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char a[105];
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
                a[top]=num1; // @@ The array 'a' is declared as char, but it stores integers. This causes truncation or incorrect storage of integer values. It should be an int array.
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
                printf("%d ",a[top]); // @@ Printing a char as %d may produce incorrect output due to sign extension or truncation. The array should be int to store integers properly.
                top--;
            }
                        
        }
    }
    
    return 0;
}