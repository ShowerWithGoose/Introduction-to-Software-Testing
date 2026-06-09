#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char a[105]; // @@ [Error: The array 'a' is declared as 'char', but the input values to be pushed are integers (e.g., 567). A char can only store values from -128 to 127, so large integers will be truncated. It should be 'int a[105]'.]
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
            if(top==100) // @@ [Error: The stack capacity is 100, so the maximum index is 99. The condition should be 'top >= 99' or 'top == 99' to check if the stack is full before pushing. Using 'top==100' allows pushing when top is 99, leading to out-of-bounds access.]
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