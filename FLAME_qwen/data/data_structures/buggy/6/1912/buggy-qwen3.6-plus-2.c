#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char a[105]; // @@ The stack should store integers, not characters. Using char will truncate integer values and cause incorrect output when printed with %d.
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
            if(top==100) // @@ Since top is a 0-based index initialized to -1, the stack is full when top reaches 99 (capacity 100). Checking top==100 allows pushing 101 elements, causing an out-of-bounds access.
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