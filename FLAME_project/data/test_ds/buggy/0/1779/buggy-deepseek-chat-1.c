#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s);
    
    for(int i=0;s[i]!='\0';i++)
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') // @@ The condition does not check that characters on both sides of '-' are of the same type (e.g., both digits, both lowercase, or both uppercase). It also does not ensure that the character after '-' is greater than the one before it; it only checks the difference is less than 26 and non-negative, which can incorrectly expand mixed types like '0-A' (digit to uppercase) or 'a-9' (lowercase to digit). Additionally, it does not handle the case where '-' appears at the start or end of the string (e.g., "-a" or "a-"), causing out-of-bounds access.
            {
                for(int q=1;q<s[i+1]-s[i-1];q++)
                {
                    printf("%c",(char)(s[i-1]+q));
                }
                
            }
        
        else
        printf("%c",s[i]);
    }

    return 0;
}