#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s);
    
    for(int i=0;s[i]!='\0';i++) // @@ Error: Loop starts at i=0, causing out-of-bounds access to s[i-1] when i=0. Should start at i=1 after printing the first character separately.
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') // @@ Error: (1) s[i-1] out of bounds when i=0. (2) Condition does not verify that both characters are of the same type (lowercase, uppercase, or digit) and within the allowed ranges [a-z],[A-Z],[0-9]. (3) Uses >=0 instead of >0, allowing expansion when characters are equal, which should not be expanded.
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