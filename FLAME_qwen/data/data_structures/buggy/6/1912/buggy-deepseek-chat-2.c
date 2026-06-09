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
            if(top==100) // @@ Error: The stack capacity is 100, but using 0-based indexing with top starting at -1, the maximum index should be 99. When top reaches 99, the stack is full (100 elements). The condition should be top >= 99 or top == 99 to correctly detect a full stack. Currently, it allows pushing when top is 99, which would write beyond the array bounds.
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
                printf("%d ",a[top]); // @@ Error: The array 'a' is declared as char, but the values being pushed and popped are integers. Using %d to print a char will produce incorrect output for values that exceed the char range (e.g., values > 127 or < -128). The array should be of type int to store integer values correctly.
                top--;
            }
                        
        }
    }
    
    return 0;
}