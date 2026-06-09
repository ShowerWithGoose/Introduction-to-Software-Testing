#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char a[105]; // @@ [The array 'a' is declared as char, but it should store integers. This causes incorrect storage and output of pushed values.]
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
                a[top]=num1;    // @@ [Storing an integer into a char array truncates the value to 1 byte, leading to data corruption.]
    
        }
        else//≥ˆ’ª
        {
            if(top==-1)
            {
                printf("error ");
            }
            else
            {    
                printf("%d ",a[top]); // @@ [Printing a char as %d may print unexpected values due to sign extension or truncation.]
                top--;
            }
                        
        }
    }
    
    return 0;
}