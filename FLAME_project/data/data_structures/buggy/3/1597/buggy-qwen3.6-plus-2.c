#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    char str[1000];
    int count=0,a=1,b;
    
    gets(str);
    int n=strlen(str);
    
    if(str[1]=='.' && str[0]=='0')
    {
        for(int i=2;i<n;i++)
        {
            if(str[i]=='0')
            {
                a++;
                continue;
            }
            else
            {
                b=a+1;
                break;
            }
        }
        for(b;b<n;b++)
        {
            count++;
            printf("%c", str[b]);
            if(count>0)
            {
                printf("."); // @@ The problem states that if the base is an integer (single significant digit), it should not have a decimal point. Here, for input 0.9, the output becomes "9.", but it should be "9". The logic incorrectly appends a decimal point after the first significant digit even when there are no subsequent digits or when the result should be an integer representation in scientific notation context as per specific formatting rules (though typically 9e-1 is preferred over 9.e-1 if 9 is considered integer part). More specifically, the code prints the digit '9', then enters the if(count>0) block because count was incremented to 1, printing a '.'. This results in "9." instead of "9".
                count=0-n;
            }
            
            
        }
        printf("e-%d", a);
    }
    
    else if(str[1]=='.' && str[0]!='0')
    {
        for(int i=0;i<n;i++)
        {
            printf("%c", str[i]);
        }
        printf("e0");
    }
    
    else if(str[1]!='.')
    {
        for(int i=0;i<n;i++)
        {
            if(str[i]!='.')
            {
                printf("%c", str[i]);
                a++;
            }
            if(count==0)
            {
                printf(".");
            }
            count++;
            if(str[i]=='.')
            {
                b=a;
            }
        }
        printf("e%d", b-2);
    }
    return 0;
}