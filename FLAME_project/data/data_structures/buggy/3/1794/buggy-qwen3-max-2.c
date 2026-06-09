#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000];
    gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; however, the main logical error is elsewhere. The real issue is in the handling of digits after the decimal point when the number has more than one digit before the decimal point.]
    int i=0;
    int len=strlen(s);
    int m=0;
    if(s[1]=='.')
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
                i++; // @@ [This skips the character after the decimal point but does not handle the loop index correctly when continuing to print remaining digits. Specifically, after incrementing i here, the next iteration of the for-loop will increment i again, causing one digit to be skipped. For example, in "87899.9999999999000999", after encountering '.', i becomes position of '.' + 1, then the for-loop increments i again, skipping the first '9' after the decimal point. This leads to missing a '9' in the output, causing "8.7899999999999000999" instead of "8.78999999999999000999".]
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