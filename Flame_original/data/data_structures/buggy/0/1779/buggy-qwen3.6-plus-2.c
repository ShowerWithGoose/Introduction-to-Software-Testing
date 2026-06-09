#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s);
    
    for(int i=0;s[i]!='\0';i++) // @@ Loop starts at i=0, but s[i-1] is accessed inside, causing out-of-bounds memory access. Should start at i=1.
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') // @@ Condition incorrectly checks character type using difference <26, which fails for mixed types like '0' and 'A'. Also uses >=0 instead of >0, allowing equal characters. Does not check if s[i+1] is '\0'.
            {
                for(int q=1;q<s[i+1]-s[i-1];q++) // @@ Relies on flawed condition; if s[i+1] is '\0', accessing it causes undefined behavior.
                {
                    printf("%c",(char)(s[i-1]+q));
                }
                
            }
        
        else
        printf("%c",s[i]);
    }

    return 0;
}