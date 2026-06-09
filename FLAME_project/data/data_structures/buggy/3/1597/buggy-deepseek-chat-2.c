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
                printf("."); // @@ This incorrectly adds a decimal point after every character, instead of only once after the first significant digit.
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
                printf("."); // @@ This adds a decimal point at the wrong position; it should be placed after the first digit, not based on count.
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