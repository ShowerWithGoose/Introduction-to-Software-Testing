#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000];
    gets(s); // @@ gets() is deprecated and removed in the C11 standard, which will cause a compilation error in modern environments. Use fgets() instead.
    int i=0;
    int len=strlen(s);
    int m=0;
    if(s[1]=='.') // @@ Assumes the decimal point is always at index 1. This is fragile and may fail for valid inputs with different formatting; it's safer to find the dot position dynamically.
    {
        if(s[0]!='0')
        {
         printf("%se0",s);
        }
    else    if(s[0]=='0')
    {
        i=2;
        while(s[i]=='0')
        {
            i++;
        }
        if(i==len-1)
        {
            printf("%ce-%d",s[i],i-1);
        }
        else
        {
            m=i-1;
            printf("%c.",s[i]);
            i++;
            while(i<len)
            {
                printf("%c",s[i]);
                i++;
            }
            printf("e-%d",m);
            
            
        }
    }
    }
    else
    {
        for(i=0;i<len;i++)
        {
            if(s[i]=='.')
            break;
        }
        m=i;
        printf("%c.",s[0]);
        for(i=1;i<len;i++)
        {
            if(s[i]=='.')
            {
                i++; // @@ Incrementing i here causes the loop to skip the character immediately following the decimal point because the for-loop's increment step will advance i again.
            }
            else
            {
                    printf("%c",s[i]);
            }
        
        }
        printf("e%d",m-1);
        
    }
    
    
    return 0;
}