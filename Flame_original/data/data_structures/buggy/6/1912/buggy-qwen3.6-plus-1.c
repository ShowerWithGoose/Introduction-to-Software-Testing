#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char a[105]; // @@ The stack is intended to store integers. Using char will cause data truncation and incorrect output when printing with %d.
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
            if(top==100) // @@ Since top is initialized to -1 and incremented before assignment, top==99 indicates the stack is full (100 elements). Checking top==100 allows exceeding the maximum capacity.
            {
                printf("error ");
            }
            else
            {
                top++;
                a[top]=num1;    
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
                printf("%d ",a[top]);
                top--;
            }
                        
        }
    }
    
    return 0;
}