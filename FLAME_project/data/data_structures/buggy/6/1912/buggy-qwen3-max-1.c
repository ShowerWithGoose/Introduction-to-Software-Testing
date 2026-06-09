#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char a[105]; // @@ [The stack array 'a' is declared as char, which can only hold values from -128 to 127 (or 0 to 255 for unsigned). However, the input value 567 exceeds this range, causing truncation or undefined behavior. It should be declared as int a[105].]
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
                a[top]=num1;    // @@ [Assigning an int (e.g., 567) to a char array element causes data loss because char cannot represent such large values. This leads to incorrect output like '55' instead of '567'.]
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
                printf("%d ",a[top]); // @@ [When printing, the truncated char value (e.g., 567 mod 256 = 55) is promoted to int and printed, resulting in wrong output.]
                top--;
            }
                        
        }
    }
    
    return 0;
}