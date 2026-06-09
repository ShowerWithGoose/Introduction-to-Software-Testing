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
            if(count>0) // @@ This condition always true after the first digit is printed, causing an extra decimal point after a single‑digit base (e.g., "3." instead of "3").
            {
                printf("."); // @@ Prints a decimal point even when there are no more digits after the first, resulting in a trailing dot.
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