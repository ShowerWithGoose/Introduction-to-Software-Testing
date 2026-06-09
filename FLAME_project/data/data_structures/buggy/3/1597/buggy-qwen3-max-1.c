#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    char str[1000];
    int count=0,a=1,b;
    
    gets(str); // @@ [Using gets() is unsafe and deprecated; more critically, it may leave newline in buffer, but the main issue here is logic errors in parsing]
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
                printf("."); // @@ [This prints a '.' after the first digit unconditionally, leading to "9." instead of "9" when only one significant digit remains]
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
                printf("."); // @@ [This prints a decimal point even when the normalized form should be an integer (only one digit), e.g., "5" not "5."]
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