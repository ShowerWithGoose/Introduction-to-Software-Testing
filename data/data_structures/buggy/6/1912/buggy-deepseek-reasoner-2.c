#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char a[105]; // @@ Array should be int to store integers correctly, not char.
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
            if(top==100) // @@ Wrong condition: stack full when top==99 (since top starts at -1, after 100 elements top=99). Should be top==99 or top>=99.
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