#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s); // @@ gets() is removed in C11 standard and causes compilation errors in modern compilers; also unsafe for buffer overflow.
    
    for(int i=0;s[i]!='\0';i++) // @@ Loop starts at i=0, but s[i-1] is accessed inside, causing out-of-bounds memory access on the first iteration.
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') // @@ Fails to verify if s[i-1] and s[i+1] are of the same type (e.g., 'Z' and 'a' differ by 7 but are different types); >=0 allows equal characters, violating the "greater than" requirement.
            {
                for(int q=1;q<s[i+1]-s[i-1];q++) // @@ Loop condition stops before reaching s[i+1], so the ending character of the expansion range is never printed.
                {
                    printf("%c",(char)(s[i-1]+q));
                }
                
            }
        
        else
        printf("%c",s[i]); // @@ When s[i] is '-', it is skipped, but s[i+1] is never printed anywhere, resulting in missing characters in the output.
    }
    return 0;
}