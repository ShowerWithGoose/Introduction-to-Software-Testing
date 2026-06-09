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
                printf("."); // @@ This incorrectly adds a decimal point after every character when count>0, but should only add it once after the first digit. For input "0.9", it prints "9." instead of "9".
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
                printf("."); // @@ This adds a decimal point unconditionally when count==0, even if the number is an integer (e.g., "12" would become "1.2"), which is incorrect. The decimal point should only be added after the first digit when there are more digits.
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