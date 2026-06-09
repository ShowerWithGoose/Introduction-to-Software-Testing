#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char a[105]; // @@ [Error: The array is declared as char type, but the input values (e.g., 567) are integers that may exceed the range of char (-128 to 127). This causes truncation or overflow, leading to incorrect output like 55 instead of 567. The array should be of type int.]
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
            if(top==100) // @@ [Error: The stack capacity is 100, so the maximum index is 99. The condition should be top >= 99 or top == 99 to check if the stack is full before pushing. Using top==100 allows an extra push beyond capacity, causing out-of-bounds access.]
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